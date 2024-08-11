#include <iostream>
using namespace std;

class XMLData {
    string xmlData;

public:
    XMLData(string pXmlData) {
        xmlData = pXmlData;
    }

    string getXMLData() {
        return xmlData;
    }
};


class DataAnalyticsTool {
    string jsonData;

public:
    DataAnalyticsTool() {}

    DataAnalyticsTool(string pJsonData) {
        jsonData = pJsonData;
    }

    virtual void analyzeData() { // virtual, so that derived classes can override
        cout << "Analyzing Data: " << jsonData << endl;
    }
};



class Client {
public:
    void ProcessData(DataAnalyticsTool* tool) {
        tool->analyzeData();
    }
};


// Convert XML to JSON
class Adapter : public DataAnalyticsTool {
    XMLData* xmlData;

public:
    Adapter(XMLData* pXmlData) {
        xmlData = pXmlData;
    }

    void analyzeData() override {
        cout << "Converting XML Data " << xmlData->getXMLData() << " to JSON Data" << endl;
        DataAnalyticsTool::analyzeData();
    }
};

int main() {
    XMLData* xmlData = new XMLData("\"Sample XML Data\"");
    DataAnalyticsTool* tool = new Adapter(xmlData);
    Client* client = new Client;
    client->ProcessData(tool);

    return 0;
}