#include<iostream>
#include<cstring>
using namespace std;

// ## Virtual Functions Example + Creation Rules

class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title = s;
            rating = r;
        }
        virtual void display(){}
};

class CWHVideo : public CWH{
    float videolength;
    public:
        CWHVideo(string s, float r, float vl) : CWH(s, r){
            videolength = vl;
        }
        void display(){
            cout<<"This is an amazing video with title: "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length of this video is "<<videolength<<endl;
        }
};
class CWHText : public CWH{
    int wordcounter;
    public:
        CWHText(string s, float r, int wc) : CWH(s, r){
            wordcounter = wc;
        }
        void display(){
            cout<<"This is an amazing text tutorial with title: "<<title<<endl;
            cout<<"Ratings: "<<rating<<" out of 5 stars"<<endl;
            cout<<"No of words in this text is "<<wordcounter<<" words"<<endl;
        }
};

int main(){
    string title;

    // for CWH Video
    title = "Django tutorial Video";
    CWHVideo djVideo(title, 4.1, 12.5);
    // djVideo.display();

    // for CWH Text
    title = "Django tutorial Text";
    CWHText djText(title, 4.19, 433);
    // djText.display();

    CWH* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;
    tuts[0]->display();
    tuts[1]->display();

    return 0;
}

/*
Rule for virtual functions
    1. They cannot be static
    2. They are accessed by object pointers
    3. Virtual functions can be a friend of another class
    4. A virtual function in base class might not be used
    5. If a virtual function is defined in base class,
    there is no necessity of redefining it in the derived class
*/