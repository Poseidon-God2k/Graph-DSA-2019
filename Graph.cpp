/************************************************************************************************************************************/
/************************************               ******   **   *****   *****   **  **         ************************************/
/************************************               **     **  ** **   ** **   ** **  **         ************************************/
/************************************               ** *** ****** *****   *****   ******         ************************************/
/************************************               **   * **  ** **  **  **      **  **         ************************************/
/************************************               ****** **  ** **   ** **      **  **         ************************************/
#include<iostream> 
#include<algorithm>
#include<fstream>
#include<queue>
#include<vector>
using namespace std;
struct node{
     char vertex;
     int value;
     node * next;
};
struct vertex{
    char name;
    node* next;
};
class Path{
    vertex vt;
    node* root;
    void insert_node(node * &root,char temp , int value){
         node* new_node=new node;
         new_node->value = value;
         new_node->vertex = temp;
        if(!root){
            root = new_node;
            return;
        }
        insert_node(root->next,temp,value);
    }
    void print(node * root){
         if(!root){ 
            cout<<"Vertex connet is: "<< root->vertex<<" connet value is: " << root->value<<endl;
            print(root->next);
         }
    }
public:
    void create_top(char name){
          vt.name =name;
          vt.next = root;
    }
    void insert(char temp , int value){
        insert_node(root, temp,value);
    }
    void print(){
       cout<<"Name of vertex: "<<vt.name<<endl;
       print(root);
    }
};
void create_graph(vector<Path>Graph,int size){
    int n= size;
    for(int i=0;i<n;i++){
        cout<<"Enter name of vertex: ";
        char temp; cin>>temp;
        Path new_path;
        new_path.create_top(temp);
        while(true){
            cout<<"if no remaind connet vertex please enter -1 in value connet  : ";
            cout<<"\n Nhap gia tri duong di: ";
            int value;cin>>value;
            if(value==-1)
            break;
            cout<<"Nhap ten dinh noi : ";
            cin>>temp;
            new_path.insert(temp,value);
        }
        Graph.push_back(new_path);
    }
}
void print_Graph(vector<Path> Graph){
    cout<<"All path in Graph is: "<<endl;
    for(int i= 0 ; i< Graph.size();i++){
        Graph[i].print();
    }
}
int main(){
    vector<Path> Graph;
    cout<<"Enter number of vertex: ";int n;cin>>n;
    create_graph(Graph,n);
    print_Graph(Graph);
}