class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        
        queue<Node*>q;
        q.push(root);
        
        bool leftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> ans(size);
            
            // now hum ye wala level process karenge 
            
            for(int i=0;i<size;i++){
                
                Node* frontNode= q.front();
                q.pop();
                int index= leftToRight ? i: size-i-1;
                ans[index]=frontNode->data;
                
                
                // ab node left or right node bhi daaldo 
                
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
            leftToRight=!leftToRight;
            
            for(auto i:ans){
                res.push_back(i);
            }
            
        }
        
        return res;
    }
};
