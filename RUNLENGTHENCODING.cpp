<<<<<<< HEAD
string encode(string src){
  int i=0,j=0;
    string ans="";
    while(j<src.size()){
        while(src[i]==src[j]){
            j++;
        }
        ans+=src[i] + to_string(j-i);
        i=j;
        
    }
    return ans;
=======
string encode(string src){
  int i=0,j=0;
    string ans="";
    while(j<src.size()){
        while(src[i]==src[j]){
            j++;
        }
        ans+=src[i] + to_string(j-i);
        i=j;
        
    }
    return ans;
>>>>>>> 839cf12cc64ea5ca6537d140390f2aaa45008b96
}