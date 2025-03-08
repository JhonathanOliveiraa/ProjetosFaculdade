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

public:
    calculadoraIPV4 (string enderecoIP){
    ip = enderecoIP;
    }
    calculadoraIPV4(string enderecoIP, string mascaraSubnet) {
        ip = enderecoIP;
        mascara = mascaraSubnet;
        cidr = -1;
    }

    bool validarIPV4();
    bool validarMascara();
    bool validarMascaraComClasse();
    string getClasseIP();
    string getMascaraPorClasse();
    int converterMascaraParaCIDR();
    string converterCIDRParaMascara(int cidr);
    string calcularEnderecoRede();
    string calcularEnderecoBroadcast();
    string getPrimeiroHost();
    string getUltimoHost();
    string getNumeroHosts();
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

bool calculadoraIPV4::validarMascaraComClasse() {
    mascara = getMascaraPorClasse();
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
            return validarMascaraComClasse();
        } catch (...) {
            return false;
        }
    }
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

int calculadoraIPV4::converterMascaraParaCIDR() {
    return cidr;
}
string calculadoraIPV4::getClasseIP() {
    if (!validarIPV4()) return "Inválido";
    int primeiroOcteto = partesIP[0];

    if (primeiroOcteto >= 1 && primeiroOcteto <= 126) return "Classe A";
    if (primeiroOcteto >= 128 && primeiroOcteto <= 191) return "Classe B";
    if (primeiroOcteto >= 192 && primeiroOcteto <= 223) return "Classe C";
    if (primeiroOcteto >= 224 && primeiroOcteto <= 239) return "Classe D (Multicast)";
    if (primeiroOcteto >= 240 && primeiroOcteto <= 255) return "Classe E (Reservado)";
    
    return "Inválido";
}

string calculadoraIPV4::getMascaraPorClasse(){
    if (getClasseIP()=="Classe A"){
        return "255.0.0.0";
    }
    if (getClasseIP()=="Classe B"){
            return "255.255.0.0";
    }
    if (getClasseIP()=="Classe C"){
            return "255.255.255.0";
    }
    return "Máscara desconhecida";
}
string calculadoraIPV4::calcularEnderecoRede() {
    vector<int> enderecoRede(4);
    for (int i = 0; i < 4; i++) {
        enderecoRede[i] = partesIP[i] & partesMascara[i];
    }
    return to_string(enderecoRede[0]) + "." + to_string(enderecoRede[1]) + "." +
           to_string(enderecoRede[2]) + "." + to_string(enderecoRede[3]);
}

string calculadoraIPV4::calcularEnderecoBroadcast() {
    vector<int> enderecoBroadcast(4);
    for (int i = 0; i < 4; i++) {
        enderecoBroadcast[i] = partesIP[i] | (~partesMascara[i] & 255);
    }
    return to_string(enderecoBroadcast[0]) + "." + to_string(enderecoBroadcast[1]) + "." +
           to_string(enderecoBroadcast[2]) + "." + to_string(enderecoBroadcast[3]);
}

string calculadoraIPV4::getPrimeiroHost() {
    if (cidr == 32) {
        return "Nenhum host disponível"; // Caso especial para /32
    }
    vector<int> net = {partesIP[0] & partesMascara[0], partesIP[1] & partesMascara[1], partesIP[2] & partesMascara[2], (partesIP[3] & partesMascara[3]) + 1};
    return to_string(net[0]) + "." + to_string(net[1]) + "." + to_string(net[2]) + "." + to_string(net[3]);
}

string calculadoraIPV4::getUltimoHost() {
    if (cidr == 32) {
        return "Nenhum host disponível"; // Caso especial para /32
    }
    vector<int> broad = {partesIP[0] | (~partesMascara[0] & 255), partesIP[1] | (~partesMascara[1] & 255), partesIP[2] | (~partesMascara[2] & 255), (partesIP[3] | (~partesMascara[3] & 255)) - 1};
    return to_string(broad[0]) + "." + to_string(broad[1]) + "." + to_string(broad[2]) + "." + to_string(broad[3]);
}

string calculadoraIPV4::getNumeroHosts() {
    int num = pow(2, 32 - cidr) - 2;
    if (num == -1) return ("Não há número de hosts para essa máscara");
    return std::to_string(num);
}

int main() {
    int option;
    string ip, mascara;
    
    cout << "Redes de Computadores II\n";
    cout << "Aluno: Jhonathan Oliveira de Almeida\n";
    cout << "Escolha o tipo de endereçamento:\n";
    cout << "1. Endereçamento com classes\n";
    cout << "2. Endereçamento sem classes - máscara na notação decimal\n";
    cout << "3. Endereçamento sem classes - máscara na notação CIDR\n";
    cout << "Digite sua opção: ";
    cin >> option;

    cout << "Digite o endereço IP (padrão n.n.n.n): ";
    cin >> ip;

    calculadoraIPV4 calculoComClasse (ip);
    
    calculoComClasse.validarMascaraComClasse();

    if (option == 1) {
        cout << "Classe do IP: " << calculoComClasse.getClasseIP() <<endl;
        if (calculoComClasse.getClasseIP()=="Classe D (Multicast)" || 
        calculoComClasse.getClasseIP()=="Classe E (Reservado)")  return 0;
        cout << "Endereço de rede: " << calculoComClasse.calcularEnderecoRede() << endl;
        cout << "Endereço de broadcast: " << calculoComClasse.calcularEnderecoBroadcast() << endl;
        cout << "Primeiro IP utilizável: " << calculoComClasse.getPrimeiroHost() << endl;
        cout << "Último IP utilizável: " << calculoComClasse.getUltimoHost() << endl;
        cout << "Número de hosts disponíveis: " << calculoComClasse.getNumeroHosts() << endl;
        
        return 1;
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
    if(option == 2){
        cout << "Máscara em notação CIDR: /" << calc.converterMascaraParaCIDR() << endl;
    }
    if(option == 3){
    cout << "Máscara em notação decimal: " << calc.converterCIDRParaMascara(calc.converterMascaraParaCIDR()) << endl;
    }
    return 0;
}