class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
       int n=row.size();
int swaps=0;
unordered_map<int,int>position;
for(int i=0;i<n;i++){ //i=0 
position[row[i]]=i; //position={0:0,2:1,1:2,3:3}
}
for(int i=0;i<n;i+=2){ // i=2 
int first=row[i];  // 0  //first=2 
int expected_partner=first^1; //0^1=1  // 2^1=3 row[3]=3 
if(row[i+1]!=expected_partner){
int partner_index=position[expected_partner]; //pos[1]=2
swap(row[i+1],row[partner_index]); //swap(row[1],row[2])= 0,1,2,3
position[row[partner_index]]=partner_index; //position[2]=2 //position[1]=1 
position[row[i+1]]=i+1;
swaps++; //swap=1
}}
return swaps;
 
    }
};