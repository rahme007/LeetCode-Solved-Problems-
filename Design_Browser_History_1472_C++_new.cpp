

#include <iostream>

using namespace std;

class BrowserHistory {
    struct node {
        string url;
        node* prev;
        node* next;
        node(string url) : url(url), prev(nullptr), next(nullptr) {}
    };
public:
    node* head;
    node* curr;
    int size;



    BrowserHistory(string homepage) {
        //initialize the parameters
        head = new node(homepage);
        curr = head;
        size = 1;

    }

    void visit(string url) {
        // clearing up all the forward history (i.e. nodes)
        node* temp = curr->next;

        while (temp) {
            node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }

        // adding the current url as a new node
        node* newNode = new node(url);
        curr->next = newNode;
        newNode->prev = curr;

        curr = curr->next;

        size++;

    }

    string back(int steps) {

        // check if the steps > size
        int realSteps = min(size, steps);
        for (int i = realSteps; i > 0; i--) {
            //traversing the history backwards (i.e. previous history)
            if (curr->prev)
                curr = curr->prev;

        }
        return curr->url;
    }

    string forward(int steps) {
        // check if the steps > size
        int realSteps = min(size, steps);

        // traversing to get the forward history
        for (int i = 0; i < realSteps; i++) {
            if (curr->next)
                curr = curr->next;
            else
                break;
        }

        return curr->url;
    }
};

int main()
{
    BrowserHistory* browserHistory = new BrowserHistory("leetcode.com");
     browserHistory->visit("google.com");
     browserHistory->visit("facebook.com");
     browserHistory->visit("youtube.com");

    string first = browserHistory->back(1);
    cout << first << endl;
    string second =browserHistory->back(1);
    cout << second << endl;
    string firstForward = browserHistory->forward(1);
    cout << firstForward << endl;
    browserHistory->visit("linkedin.com");
    string secondForward = browserHistory->forward(2);
    cout << secondForward << endl;
    string fourth = browserHistory->back(2);
    cout << fourth << endl;
    string fifth = browserHistory->back(7);
    cout << fifth << endl;

    return 0;



}


