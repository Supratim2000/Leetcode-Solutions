//Unoptimised approach(2 passes)
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* temp=head;
        int size=getSize();
        int random=rand()%size;
        for(int i=0;i<random;i++)
            temp=temp->next;
        return temp->val;
    }

    int getSize() {
        ListNode* temp=head;
        int size=0;
        while(temp)
        {
            size++;
            temp=temp->next;
        }
        return size;
    }
};

//Optimised approach(Reservoir Sampling(Single pass))
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* temp=head;
        int randomPoint=-1;
        int indexTillNow=0;
        while(temp)
        {
            indexTillNow++;
            int random=rand()%indexTillNow;
            if(random==indexTillNow-1)
                randomPoint=temp->val;
            temp=temp->next;
        }
        return randomPoint;
    }
};
