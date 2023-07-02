class UnionFind{
  int n,num;
  vector<int> sz,parent;
public:
  UnionFind()=default;
  UnionFind(int n):n(n),num(n),sz(n,1),parent(n,0){iota(parent.begin(),parent.end(),0);}
  
  int leader(int x){ 
    assert(0<=x and x<n);
    return (x==parent[x]? x : parent[x]=leader(parent[x])); 
  }
  
  bool same(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    return leader(x)==leader(y); 
  }
  
  bool merge(int x,int y){
    assert(0<=x and x<n and 0<=y and y<n);
    x=leader(x);y=leader(y);
    if(x==y)return false;
    if(sz[x]<sz[y])swap(x,y);
    sz[x]+=sz[y];
    parent[y]=x;
    num--;
    return true;
  }
  
  int size(const int x){
    assert(0<=x and x<n);
    return sz[leader(x)];
  }
  
  int count()const{
    return num;
  }
};