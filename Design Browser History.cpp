class BrowserHistory {
public:
    class DLL
    {
        public:
            string val;
            DLL* next;
            DLL* prev;
            DLL(string val)
            {
                this->val=val;
                next=nullptr;
                prev=nullptr;
            }
    };
    
    DLL* head=nullptr;
    
    BrowserHistory(string homepage) {
        head=new DLL(homepage);
    }
    
    void visit(string url) {
        DLL* temp=new DLL(url);
        temp->prev=head;
        head->next=temp;
        head=temp;
    }
    
    string back(int steps) {
        for(int i=0;i<steps && head->prev;i++)
            head=head->prev;
        return head->val;
    }
    
    string forward(int steps) {
        for(int i=0;i<steps && head->next;i++)
            head=head->next;
        return head->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
