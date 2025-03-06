#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class IPv4Calculator {
private:
    string ip;
    string mask;
    vector<int> ipParts;
    vector<int> maskParts;
    int cidr;

public:
    IPv4Calculator(string ipAddress, string subnetMask) {
        ip = ipAddress;
        mask = subnetMask;
        cidr = -1;
    }

    bool validateIPv4();
    bool validateMask();
    string getIPClass();
    int convertMaskToCIDR();
    string convertCIDRToMask(int cidr);
    string calculateNetworkAddress();
    string calculateBroadcastAddress();
    string getFirstUsableHost();
    string getLastUsableHost();
    int getHostCount();
};

bool IPv4Calculator::validateIPv4() {
    stringstream ss(ip);
    string segment;
    int count = 0;

    while (getline(ss, segment, '.')) {
        if (count >= 4) return false;
        try {
            int num = stoi(segment);
            if (num < 0 || num > 255) return false;
            ipParts.push_back(num);
        } catch (...) {
            return false;
        }
        count++;
    }
    return count == 4;
}

bool IPv4Calculator::validateMask() {
    if (mask.find(".") != string::npos) {
        stringstream ss(mask);
        string segment;
        int count = 0, maskValue = 0;
        bool zeroFound = false;

        while (getline(ss, segment, '.')) {
            if (count >= 4) return false;
            try {
                int num = stoi(segment);
                if (num < 0 || num > 255) return false;
                maskParts.push_back(num);
            } catch (...) {
                return false;
            }
            count++;
        }

        if (count != 4) return false;
        
        for (int i = 0; i < 4; i++) {
            for (int bit = 7; bit >= 0; bit--) {
                if (maskParts[i] & (1 << bit)) {
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
            cidr = stoi(mask);
            if (cidr < 0 || cidr > 32) return false;
            mask = convertCIDRToMask(cidr);
            return validateMask();
        } catch (...) {
            return false;
        }
    }
}

string IPv4Calculator::convertCIDRToMask(int cidr) {
    vector<int> mask(4, 0);
    for (int i = 0; i < cidr; i++) {
        mask[i / 8] |= (1 << (7 - (i % 8)));
    }
    return to_string(mask[0]) + "." + to_string(mask[1]) + "." + to_string(mask[2]) + "." + to_string(mask[3]);
}

string IPv4Calculator::getIPClass() {
    if (!validateIPv4()) return "Inválido";
    int firstOctet = ipParts[0];

    if (firstOctet >= 1 && firstOctet <= 126) return "Classe A";
    if (firstOctet >= 128 && firstOctet <= 191) return "Classe B";
    if (firstOctet >= 192 && firstOctet <= 223) return "Classe C";
    if (firstOctet >= 224 && firstOctet <= 239) return "Classe D (Multicast)";
    if (firstOctet >= 240 && firstOctet <= 255) return "Classe E (Reservado)";
    
    return "Inválido";
}

string IPv4Calculator::calculateNetworkAddress() {
    vector<int> networkAddress(4);
    for (int i = 0; i < 4; i++) {
        networkAddress[i] = ipParts[i] & maskParts[i];
    }
    return to_string(networkAddress[0]) + "." + to_string(networkAddress[1]) + "." +
           to_string(networkAddress[2]) + "." + to_string(networkAddress[3]);
}

string IPv4Calculator::calculateBroadcastAddress() {
    vector<int> broadcastAddress(4);
    for (int i = 0; i < 4; i++) {
        broadcastAddress[i] = ipParts[i] | (~maskParts[i] & 255);
    }
    return to_string(broadcastAddress[0]) + "." + to_string(broadcastAddress[1]) + "." +
           to_string(broadcastAddress[2]) + "." + to_string(broadcastAddress[3]);
}

string IPv4Calculator::getFirstUsableHost() {
    vector<int> net = {ipParts[0] & maskParts[0], ipParts[1] & maskParts[1], ipParts[2] & maskParts[2], (ipParts[3] & maskParts[3]) + 1};
    return to_string(net[0]) + "." + to_string(net[1]) + "." + to_string(net[2]) + "." + to_string(net[3]);
}

string IPv4Calculator::getLastUsableHost() {
    vector<int> broad = {ipParts[0] | (~maskParts[0] & 255), ipParts[1] | (~maskParts[1] & 255), ipParts[2] | (~maskParts[2] & 255), (ipParts[3] | (~maskParts[3] & 255)) - 1};
    return to_string(broad[0]) + "." + to_string(broad[1]) + "." + to_string(broad[2]) + "." + to_string(broad[3]);
}

int IPv4Calculator::getHostCount() {
    return pow(2, 32 - cidr) - 2;
}

int main() {
    int option;
    string ip, mask;

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
        cin >> mask;
    } else if (option == 2) {
        cout << "Digite a máscara de sub-rede em notação decimal (ex: 255.255.255.0): ";
        cin >> mask;
    } else if (option == 3) {
        cout << "Digite a máscara de sub-rede na notação CIDR (ex: 24): ";
        cin >> mask;
    } else {
        cout << "Opção inválida!" << endl;
        return 1;
    }

    IPv4Calculator calc(ip, mask);

    if (!calc.validateIPv4()) {
        cout << "Endereço IPv4 inválido!" << endl;
        return 1;
    }

    if (!calc.validateMask()) {
        cout << "Máscara de sub-rede inválida!" << endl;
        return 1;
    }

    if (option == 1) {
        cout << "Classe do IP: " << calc.getIPClass() << endl;
    }
    cout << "Endereço de rede: " << calc.calculateNetworkAddress() << endl;
    cout << "Endereço de broadcast: " << calc.calculateBroadcastAddress() << endl;
    cout << "Primeiro IP utilizável: " << calc.getFirstUsableHost() << endl;
    cout << "Último IP utilizável: " << calc.getLastUsableHost() << endl;
    cout << "Número de hosts disponíveis: " << calc.getHostCount() << endl;

    return 0;
}
