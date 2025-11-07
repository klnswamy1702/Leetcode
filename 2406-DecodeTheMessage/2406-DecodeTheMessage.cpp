// Last updated: 07/11/2025, 13:40:46
// class Solution {
// public:
//     string decodeMessage(string key, string message) {
        
// //         Algorithm
// // 1. Create mapping of first occurence of every character corresponding to character in alphabetical order
// // 2. Now from the mapping created above, just assign mapped value to old value and that's our answer.
//         // Time - O(m + n)
//         // Space - O(26)
        
//         vector<char> map(26);  
//     //create mapping
//     for(auto i:key){
        
//         // current is not a space and is not found before
//         if(i!=32 and !map[i-'a']) map[i-'a']= (k+'a') , k++;
// 	}
    
//     //then update characters inplace in message string according to mapping except for spaces
//     for(int i=0;i<m.size();i++) if(m[i]!=32) m[i]= map[m[i]-'a'];
//     return m;
        
        
//         // string s="";
//         // int n=key.size();
//         // vector<bool> v(26,false);
//         // for(int i=0;i<key.size();i++)
//         // {
//         //     if(key[i]!=' ')
//         //     {
//         //         if(!v[key[i]-'a'])
//         //         {
//         //             s+=key[i];
//         //             v[key[i]-'a']=true;
//         //         }
//         //     }
//         // }
//         // string abc="abcdefghijklmnopqrstuvwxyz";
//         // unordered_map<char,char> mp;
//         // for(int i=0;i<26;i++)
//         // {
//         //     mp[s[i]]=abc[i];
//         // }
//         // string ans="";
//         // for(int i=0;i<message.size();i++)
//         // {
//         //     if(message[i]==' ')
//         //     {
//         //         ans+=' ';
//         //     }
//         //     else
//         //     {
//         //         ans+=mp[message[i]];
//         //     }
//         // }
//         // return ans;
//     }
// };




// class Solution {
// public:
//     string decodeMessage(string k, string m) {
//       map<char,char>mp;
//         char temp  = 'a';
//         for(int i = 0; i < k.length(); i++) {
//             if(k[i] != ' ' && mp.find(k[i]) == mp.end()) {
//                 mp[k[i]] = temp;
//                 temp++;
//             }
            
//         }
        
//         string res = "";
        
//         for(int i = 0; i < m.length(); i++) {
//             if(m[i] != ' ') {
//                 res+= mp[m[i]];
//             }
//             else {
//                 res+= " ";
//             }
//         }
        
//         return res;
//     }
// };



class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp; 
        int i = 0; 
        for (auto& ch : key) 
            if (ch != ' ' && !mp.count(ch)) mp[ch] = (i++) + 'a';  
        string ans; 
        for (auto& ch : message) 
            ans.push_back(ch != ' ' ? mp[ch] : ch); 
        return ans; 
    }
};