#include <iostream>
using namespace std;

// General Button
class IButton {
public:
    // Pure Virtual function = Any class which inherits from IButton, will have to implement this function
    virtual void press() = 0;
};

// Button of Macbook type
class MacButton : public IButton {
public:
    void press() {
        cout <<"Mac Button Pressed"<<endl;
    }
};

// Button of Windows type
class WinButton : public IButton {
public:
    void press() {
        cout <<"Win Button Pressed"<<endl;
    }
};



// General Text Box
class ITextBox {
public:
    virtual void showText() = 0;
};

// TextBox of Macbook type
class MacTextBox : public ITextBox {
public:
    void showText() {
        cout <<"Showing Mac TextBox"<<endl;
    }
};

// TextBox of Windows type
class WinTextBox : public ITextBox {
public:
    void showText() {
        cout <<"Showing Win TextBox"<<endl;
    }
};



// General Factory
class IFactory {
public:
    virtual IButton* createButton() = 0;
    virtual ITextBox* createTextBox() = 0;
};

// Factory of Macbook type
class MacFactory : public IFactory {
public:
    IButton* createButton() {
        return new MacButton();
    }
    ITextBox* createTextBox() {
        return new MacTextBox();
    }
};

// Factory of Windows type
class WinFactory : public IFactory {
public:
    IButton* createButton() {
        return new WinButton();
    }
    ITextBox* createTextBox() {
        return new WinTextBox();
    }
};



// Class that creates Factories
class GUIAbstractFactory {
public:
    // Since this class has only one function, let's not create object to call this function. Hence make it static
    IFactory* createFactory(string osType) {
        if(osType == "mac") {
            return new MacFactory();
        }
        else if(osType == "windows") {
            return new WinFactory();
        }
        return new MacFactory();
    }
};



int main() {
    cout<<"Enter your machine OS"<<endl;
    string osType;
    cin>>osType;

    GUIAbstractFactory guifac;
    IFactory* fact = guifac.createFactory(osType);

    IButton* button = fact->createButton();
    button->press();

    ITextBox* textBox = fact->createTextBox();
    textBox->showText();
}