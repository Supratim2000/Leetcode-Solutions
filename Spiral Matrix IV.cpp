class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        ListNode* p=head;
        int a=0;
        int b=n-1;
        int c=0;
        int d=m-1;
        int dir=0;
        //0->right, 1->down, 2->left, 3->up
        while(p)
        {
            if(dir==0)
            {
                for(int i=a;i<=b && p;i++)
                {
                    mat[c][i]=p->val;
                    p=p->next;
                }
                c++;
            }
            else if(dir==1)
            {
                for(int i=c;i<=d && p;i++)
                {
                    mat[i][b]=p->val;
                    p=p->next;
                }
                b--;
            }
            else if(dir==2)
            {
                for(int i=b;i>=a && p;i--)
                {
                    mat[d][i]=p->val;
                    p=p->next;
                }
                d--;
            }
            else
            {
                for(int i=d;i>=c && p;i--)
                {
                    mat[i][a]=p->val;
                    p=p->next;
                }
                a++;
            }
            dir=(dir+1)%4;
        }
        return mat;
    }
};
