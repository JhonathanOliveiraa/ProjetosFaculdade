#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class calculadoraIPV4 {
private:
    string ip;
    string mascara;
    vector<int> partesIP;
    vector<int> partesMascara;
    int cidr;
//teste
public:
    calculadoraIPV4(string enderecoIP, string mascaraSubnet) {
        ip = enderecoIP;
        mascara = mascaraSubnet;
        cidr = -1;
    }

    bool validarIPV4();
    bool validarMascara();
    string getClasseIP();
    int converterMascaraParaCIDR();
    string converterCIDRParaMascara(int cidr);
    string calcularEnderecoRede();
    string calcularEnderecoBroadcast();
    string getPrimeiroHost();
    string getUltimoHost();
    int getNumeroHosts();
};

bool calculadoraIPV4::validarIPV4() {
    stringstream ss(ip);
    string segment;
    int count = 0;

    while (getline(ss, segment, '.')) {
        if (count >= 4) return false;
        try {
            int num = stoi(segment);
            if (num < 0 || num > 255) return false;
            partesIP.push_back(num);
        } catch (...) {
            return false;
        }
        count++;
    }
    return count == 4;
}

bool calculadoraIPV4::validarMascara() {
    if (mascara.find(".") != string::npos) {
        stringstream ss(mascara);
        string segment;
        int count = 0, maskValue = 0;
        bool zeroFound = false;

        while (getline(ss, segment, '.')) {
            if (count >= 4) return false;
            try {
                int num = stoi(segment);
                if (num < 0 || num > 255) return false;
                partesMascara.push_back(num);
            } catch (...) {
                return false;
            }
            count++;
        }

        if (count != 4) return false;
        
        for (int i = 0; i < 4; i++) {
            for (int bit = 7; bit >= 0; bit--) {
                if (partesMascara[i] & (1 << bit)) {
                    if (zeroFound) return false;
                    maskValue++;
                } else {
                    zeroFound = true;
                }
            }
        }
        cidr = maskValue;
        return true;
    } else {
        try {
            cidr = stoi(mascara);
            if (cidr < 0 || cidr > 32) return false;
            mascara = converterCIDRParaMascara(cidr);
            return validarMascara();
        } catch (...) {
            return false;
        }
    }
}

string calculadoraIPV4::converterCIDRParaMascara(int cidr) {
    vector<int> mascara(4, 0);
    for (int i = 0; i < cidr; i++) {
        mascara[i / 8] |= (1 << (7 - (i % 8)));
    }
    return to_string(mascara[0]) + "." + to_string(mascara[1]) + "." + to_string(mascara[2]) + "." + to_string(mascara[3]);
}

string calculadoraIPV4::getClasseIP() {
    if (!validarIPV4()) return "Inválido";
    int firstOctet = partesIP[0];

    if (firstOctet >= 1 && firstOctet <= 126) return "Classe A";
    if (firstOctet >= 128 && firstOctet <= 191) return "Classe B";
    if (firstOctet >= 192 && firstOctet <= 223) return "Classe C";
    if (firstOctet >= 224 && firstOctet <= 239) return "Classe D (Multicast)";
    if (firstOctet >= 240 && firstOctet <= 255) return "Classe E (Reservado)";
    
    return "Inválido";
}

string calculadoraIPV4::calcularEnderecoRede() {
    vector<int> networkAddress(4);
    for (int i = 0; i < 4; i++) {
        networkAddress[i] = partesIP[i] & partesMascara[i];
    }
    return to_string(networkAddress[0]) + "." + to_string(networkAddress[1]) + "." +
           to_string(networkAddress[2]) + "." + to_string(networkAddress[3]);
}

string calculadoraIPV4::calcularEnderecoBroadcast() {
    vector<int> broadcastAddress(4);
    for (int i = 0; i < 4; i++) {
        broadcastAddress[i] = partesIP[i] | (~partesMascara[i] & 255);
    }
    return to_string(broadcastAddress[0]) + "." + to_string(broadcastAddress[1]) + "." +
           to_string(broadcastAddress[2]) + "." + to_string(broadcastAddress[3]);
}

string calculadoraIPV4::getPrimeiroHost() {
    vector<int> net = {partesIP[0] & partesMascara[0], partesIP[1] & partesMascara[1], partesIP[2] & partesMascara[2], (partesIP[3] & partesMascara[3]) + 1};
    return to_string(net[0]) + "." + to_string(net[1]) + "." + to_string(net[2]) + "." + to_string(net[3]);
}

string calculadoraIPV4::getUltimoHost() {
    vector<int> broad = {partesIP[0] | (~partesMascara[0] & 255), partesIP[1] | (~partesMascara[1] & 255), partesIP[2] | (~partesMascara[2] & 255), (partesIP[3] | (~partesMascara[3] & 255)) - 1};
    return to_string(broad[0]) + "." + to_string(broad[1]) + "." + to_string(broad[2]) + "." + to_string(broad[3]);
}

int calculadoraIPV4::getNumeroHosts() {
    return pow(2, 32 - cidr) - 2;
}

int main() {
    int option;
    string ip, mascara;

    cout << "Escolha o tipo de endereçamento:\n";
    cout << "1. Endereçamento com classes\n";
    cout << "2. Endereçamento sem classes – máscara na notação decimal\n";
    cout << "3. Endereçamento sem classes – máscara na notação CIDR\n";
    cout << "Digite sua opção: ";
    cin >> option;

    cout << "Digite o endereço IPv4: ";
    cin >> ip;

    if (option == 1) {
        cout << "Escolha a máscara de sub-rede na notação CIDR (0-32): ";
        cin >> mascara;
    } else if (option == 2) {
        cout << "Digite a máscara de sub-rede em notação decimal (ex: 255.255.255.0): ";
        cin >> mascara;
    } else if (option == 3) {
        cout << "Digite a máscara de sub-rede na notação CIDR (ex: 24): ";
        cin >> mascara;
    } else {
        cout << "Opção inválida!" << endl;
        return 1;
    }

    calculadoraIPV4 calc(ip, mascara);

    if (!calc.validarIPV4()) {
        cout << "Endereço IPv4 inválido!" << endl;
        return 1;
    }

    if (!calc.validarMascara()) {
        cout << "Máscara de sub-rede inválida!" << endl;
        return 1;
    }

    if (option == 1) {
        cout << "Classe do IP: " << calc.getClasseIP() << endl;
    }
    cout << "Endereço de rede: " << calc.calcularEnderecoRede() << endl;
    cout << "Endereço de broadcast: " << calc.calcularEnderecoBroadcast() << endl;
    cout << "Primeiro IP utilizável: " << calc.getPrimeiroHost() << endl;
    cout << "Último IP utilizável: " << calc.getUltimoHost() << endl;
    cout << "Número de hosts disponíveis: " << calc.getNumeroHosts() << endl;

    return 0;
}
