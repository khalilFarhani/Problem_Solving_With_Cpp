#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
};

class Solution {
  public:
//problem 1: Find duplicates in an array
    vector<int> duplicates(long long arr[], int n) {
        sort(arr,arr+n);
        vector<int> result;

        for(int i=1;i<n;i++) {
            if(arr[i]==arr[i-1] && find(result.begin(),result.end(),arr[i])==result.end())
                result.push_back(arr[i]);
        }

        if(result.size()==0)
           result.push_back(-1);

        return result;
    }

//Problem 2: Merge the two lists into one sorted list
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;
        ListNode* tmp1=list1;
        ListNode* tmp2=list1;
        while(tmp1->next != NULL) {
            tmp1=tmp1->next;
        }
        tmp1->next=list2;

        for(tmp1=list1 ; tmp1!=NULL ; tmp1=tmp1->next) {
            for(tmp2=tmp1->next ; tmp2!=NULL ; tmp2=tmp2->next) {
                if(tmp2->val < tmp1->val) {
                    int num=tmp1->val;
                    tmp1->val=tmp2->val;
                    tmp2->val=num;
                }
            }
        }
        return list1;
    }


//Problem 3: find missing number in array
    int missingNumber(vector<int>& array, int n) {
        int sum=(n * (n+1))/2;
        for(int i=0;i<array.size();i++) {
            sum-=array[i];
        }
        return sum;
    }



//Problem 4: Given a roman numeral, convert
    int romanToInt(string s) {
        int number;
        int sum=0;
        for(int i=s.length()-1;i>=0;i--) {
            switch(s[i]) {
                case 'I' :
                    number=1;
                    break;
                case 'V' :
                    number=5;
                    break;
                case 'X' :
                    number=10;
                    break;
                case 'L' :
                    number=50;
                    break;
                case 'C' :
                    number=100;
                    break;
                case 'D' :
                    number=500;
                    break;
                case 'M' :
                    number=1000;
                    break;
            }
            if((s[i]== 'X' || s[i]=='V') && i>0 && s[i-1]=='I')
            {
                number-=1;
                i--;
            }
            else if((s[i]== 'C' || s[i]=='L') && i>0 && s[i-1]=='X')
            {
                number-=10;
                i--;
            }
            else if((s[i]== 'D' || s[i]=='M') && i>0 && s[i-1]=='C')
            {
                number-=100;
                i--;
            }
            sum+=number;
        }
        return sum;
    }


//Problem 5: Given an integer target,return true if target is in matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++) {
           for(int j=0;j<matrix[i].size();j++) {
               if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }

//Problem 6: remove the duplicates such that each unique element appears only once and return sorted
    void removeDuplicates(vector<int>&nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
            {
                nums.erase(nums.begin() + i, nums.begin() + i + 1);
                i--;
            }
        }
    }


/*Problem 7: Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.*/
    int count(ListNode* head) {
        int count=0;
        while(head != NULL) {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* N=NULL;
        ListNode* tmp=head;
        ListNode* newHead=tmp;
        vector<ListNode*>v;

        while(tmp!= NULL) {
            int kTmp=k;
            if(count(tmp)>=k){
                while(kTmp-- && tmp !=NULL) {
                    newHead=tmp;
                    tmp=tmp->next;
                    newHead->next=N;
                    N=newHead;
                }
                v.push_back(newHead);
                N=NULL;
            }
            else{
                 v.push_back(tmp);
                 break;
            }  
        }
       

        for(int i=0;i<v.size()-1;i++) {
            tmp=v[i];
            while(tmp->next != NULL) {
                tmp=tmp->next;
            }
            tmp->next=v[i+1];
        }
        return v[0];
}


//Problem 8: Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2) {
        vector <int> v=nums1;
        for(int i=0;i<nums2.size();i++) {
            v.push_back(nums2[i]);
        }
        sort(v.begin(),v.end());
        if(v.size()%2==0)
        {
            return((double)(v[v.size()/2]+v[v.size()/2 - 1])/2);
        }
        else return v[v.size()/2];
};

//Problem 9: reverse Integer
    int reverse(int x) {
            long res=0;
            while(x != 0) {
                res = res * 10;
                res+=x%10;
                x/=10;
            }
            
            if(res>INT_MAX || res <INT_MIN) return 0;
            return res;
        }

//Problem 10: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    int isValid(string str) {
            stack <char> st ;
            int i=0;
            while(i<str.length()) {
                if(str[i] == '{' || str[i] == '[' || str[i]=='(') 
                    st.push(str[i]);
                else if(!st.empty()) {
                    char top=st.top();
                    if((top=='{' && str[i]=='}') || (top=='[' && str[i]==']') || (top=='(' && str[i]==')'))
                        st.pop();
                    else 
                        return false;
                }
                else return false;
                i++;
            }
            if(st.empty())
                return true;
            return false;
    }

//Problem 11: Remove Nth Node From End of List
    int countNode(ListNode* head) {
        int count=0;
        while(head != NULL ) {
            count++;
            head=head->next;
        }
        return count;
    } 
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        n=countNode(head)-n;
        int i=0;
        while(i<n && curr!=NULL) {
            prev=curr;
            curr=curr->next;
            i++;
        }
        if(curr!=NULL) {
            if(prev==NULL) 
                head=head->next;
            else 
                prev->next=curr->next;  
            delete curr;
        }
        return head;
    } 

//Problem 12:  swap every two adjacent nodes and return its head
    ListNode* swapPairs(ListNode* head) {
      ListNode* tmp=head;
      while(tmp!=NULL && tmp->next !=NULL) {
          int val=tmp->val;
          tmp->val=tmp->next->val;
          tmp->next->val=val;
          tmp=tmp->next->next;
      }  
      return head;
    }

//Problem 13:  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++) {
            int j=0;
            int k=i;
            while(haystack[i] == needle[j] && j<needle.length() && i<haystack.length()) {
                 j++;
                 i++;
            }
            if(j>=needle.length()) 
                 return i-needle.length();
            i=k;
        }
        return -1;
    }

//Problem 14: Given a string s consisting of words and spaces, return the length of the last word in the string. A word is a maximal substring consisting of non-space characters only. 
int lengthOfLastWord(string s) {
        bool isFirst=true;
        int i=s.length()-1;
        int last=-1;
        int first=-1;
        while(i>=0) {
            if(isFirst && s[i] != ' ') {
                last=i;
                isFirst=false;
            }
            if(s[i] != ' ' && (i==0 || s[i-1]==' ')){
                first=i;
                break;
            }
            i--;
        }
        return s.substr(first,last-first+1).length();
    }


//Problem 15: You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.Increment the large integer by one and return the resulting array of digits.
vector<int> plusOne(vector<int>& digits) {
       int rest=1;
       int i=digits.size()-1;
       int sum;
       while(i>=0 && rest>0) {
           int sum=digits[i]+rest;
           rest=sum/10;
           if(rest>0)
              digits[i]=sum%10;
           else{
               digits[i]++;
           }
           i--;
       }
       if(rest>0) {
           digits.insert(digits.begin(),rest);
       }
       return digits;
    }


//Problem 16: Given two binary strings a and b, return their sum as a binary string.

 string addNumberOfZero(string s,int numberOfZero) {
        for(int i=0;i<numberOfZero;i++) {
            s = '0'+s;
        }
        return s;
    }
    string addBinary(string a, string b) {
        if(a.length()>b.length()) 
            b=addNumberOfZero(b,a.length()-b.length());
        else 
            a=addNumberOfZero(a,b.length()-a.length());
        int rest=0;
        string s="";
        for(int i=a.length()-1;i>=0;i--) {
            int sum=int(a[i]-48)+int(b[i]-48)+rest;
            if(sum==2) {
                rest=1;
                s='0' + s;
            }
            else  if(sum==3) {
                rest=1;
                s='1' + s;
            }
            else  {
                rest=0;
                if(sum==1)  
                   s='1' + s;
                else
                   s='0' + s; 
            }
        }

        if(rest==1) 
            s='1' + s; 
        
        return s;
    }

//Problem 17: Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) 
            return head;
        ListNode* tmp=head;
        ListNode* eff;
        while(tmp->next != NULL) {
            if(tmp->val == tmp->next->val) {
                eff=tmp->next;
                tmp->next=eff->next;
                delete eff;
            }
            else {
                tmp=tmp->next;
            }
        }
        return head;
        


    }

//Problem 18: Given the root of a binary tree, return the sum of all left leaves. 
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
    int sumOfLeftLeaves(TreeNode* root) {
        if(root != NULL) {
            if(root->left != NULL && root->left->left == NULL && root->left->right == NULL) {
                return root->left->val + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);;
            }
            else {
                return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
            }
        }
        else return 0;
    }

//Problem 19: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
bool isPalindrome(string s) {
        string s2="";
        for(int i=0;i<s.length();i++) {
            if(s[i]>96 && s[i]<123 || s[i]>47 && s[i]<58) 
                s2+=s[i];
            else if(s[i]>64 && s[i]<91)
                s2+=s[i]+32;
        }
        for(int i=0;i<s2.length()/2;i++) {
            if(s2[i] != s2[s2.length()-1-i])
                return false;
        }
        return true;
    }

//Problem 19: other method
bool isPalindrom(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<j) {
            if(!isalnum(s[i])) {
                i++;
                continue;
            }
            if(!isalnum(s[j])) {
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])) 
                return false;
            i++;
            j--;
        }
        return true;
    }


//Problem 20: Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i] != nums[i+1]) {
                return nums[i];
            }
            i++;
        }
        return nums[nums.size()-1];
    }


//Problem 21: Given two strings s and t, return true if t is an anagram of s, and false otherwise. An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. 
//s and t consist of lowercase English letters.
bool isAnagram(string s, string t) {
        int lenS=s.length();
        int lenT=t.length();
        if(lenS != lenT) 
            return false;
        int arr[26]={0};
        for(int i=0;i<lenS;i++) {
            arr[s[i]-97]++;
            arr[t[i]-97]--;
        }
        for(int i=0;i<26;i++) {
            if(arr[i] != 0)
                return false;
        }
        return true;
    }


//Problem 22: Given an integer num, repeatedly add all its digits until the result has only one digit, and return it. and num >= .0
int addDigits(int num) {
        while(num>9) {
            int tmp=0;
            while(num > 9) {
                tmp+=num % 10;
                num=num / 10;
            }
            tmp+=num;
            num=tmp;
        }
        return num;
    }


//Problem 23: Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr != nullptr) {
            if(curr->val == val) {
                if(prev==nullptr) {
                    head=curr->next;
                    delete curr;
                    curr=head;
                } else {
                    curr=curr->next;
                    delete prev->next;
                    prev->next=curr;
                }
            } else {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }


//Problem 24: You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
 int convertListToNumber(ListNode* l) {
        int res=0;
        while(l != nullptr){
            res*=10;
            res+=l->val;
            l=l->next;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=convertListToNumber(l1)+convertListToNumber(l2);
        ListNode* l3=nullptr;
        ListNode* tmp=nullptr;
        if(sum == 0)
        {
            l3=new ListNode(0);
            l3->next=nullptr;
        }
        while(sum != 0) {
            l3=new ListNode(sum%10);
            sum /= 10;
            l3->next=tmp;
            tmp=l3;
        }
        return l3;
    }

//Problem 25:Given the head of a singly linked list, reverse the list, and return the reversed list.
 ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* head2=nullptr;
        ListNode* curr=head;
        while(curr != nullptr) {
            tmp=curr;
            curr=curr->next;
            tmp->next=head2;
            head2=tmp;
        }
        return head2;
 }


//Problem 24 (method 2):  You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        
        ListNode* tmp1=l1;
        ListNode* tmp2=l2;
        ListNode* result=nullptr;
        ListNode* newNode;
        
        int rest=0;
        while(tmp1 != nullptr || tmp2 != nullptr) {
            int sum=rest;
            if(tmp1!=nullptr){
                sum+=tmp1->val;
                tmp1=tmp1->next;
            }
            if(tmp2!=nullptr) {
                sum+=tmp2->val;
                tmp2=tmp2->next;
            }
            if(sum>9) {
                sum %= 10;
                rest = 1;
            }
            else 
                rest=0;
            
            newNode = new ListNode(sum);

            newNode->next=result;
            result=newNode;
        }
        if(rest != 0) {
            newNode = new ListNode(rest);
            newNode->next=result;
            result=newNode;
        }
        return result;
    }

//Problem 26: Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        for(int i=0;i<nums1.size();i++) {
            if(find(nums2.begin(),nums2.end(), nums1[i]) != nums2.end() && find(result.begin(),result.end(),nums1[i]) == result.end())
            result.push_back(nums1[i]);
        }
        return result;
    }


//Problem 27: sort by selection
vector<int> sortBySelection(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
		    int min = i;
		    for (int j = i+1; j < nums.size(); j++) 
			    if (nums[j] < nums[min])
				    min = j;
		    int tmp = nums[i];
		    nums[i] = nums[min];
		    nums[min] = tmp;
	    }
        return nums;
    }

//Problem 28: insertion sort
vector<int> insertionSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		int nb = nums[i];
		int j = i-1;
		while (nb < nums[j] && j >= 0 ) {
			nums[j+1] = nums[j];
			j--;
		}
		nums[j + 1] = nb;
	}
    return nums;
}

//Problem 29: bubble sorting
vector<int> bubbleSorting(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size()-1-i; j++) {
			if (nums[j] > nums[j + 1]) {
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
    return nums;
}

//problem 30: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
//Merge nums1 and nums2 into a single array sorted in non-decreasing order.
//The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m!=nums1.size()) {
            nums1.pop_back();
        }
        for(int i=0;i<n;i++) {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
    }

//problem 31: Given the roots of two binary trees p and q, write a function to check if they are the same or not.
//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p != nullptr && q != nullptr)
            if(p->val == q->val)
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            else 
                return false;
        else if(p == nullptr && q == nullptr)
            return true;
        else 
            return false;
    }

//Problem 32: Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
bool canConstruct(string ransomNote, string magazine) {
        int arr[26]={0};
        for(int i=0;i<ransomNote.length();i++) {
            arr[ransomNote[i]-97]--;
        }
        for(int i=0;i<magazine.length();i++) {
            arr[magazine[i]-97]++;
        }
        for(int i=0;i<26;i++) {
            if(arr[i]<0) 
                return false;
        }
        return true;
}

//Problem 32(method 2): Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//Each letter in magazine can only be used once in ransomNote.
bool canConstruct2(string ransomNote, string magazine) {
        for(int i=0;i<ransomNote.length();i++) {
            int index=magazine.find(ransomNote[i]);
            if(index == string::npos)
                return false;
            else 
                magazine.erase(magazine.begin()+index,magazine.begin()+index+1);
        }
        return true;     
    }

//Problem 33: Binary Search 
int search(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j) {
            int mid=(i+j)/2;
            if(nums[mid]==target) 
                return mid;
            else if(target>nums[mid]) 
                i=mid+1;
            else
                j=mid-1;
        }
        return -1;
    }


//Problem 34: reverse String with stack
string reverseStringWithStack(string str) {
    stack<char>st;
    for (char i : str) {
        st.push(i);
    }
    int j = 0;
    while (!st.empty()) {
        str[j] = st.top();
        j++;
        st.pop();
    }
    return str;
}

//Problem 35: reverse String 
string reverseString(string str) {
    for (int i = 0; i < str.length()/2; i++) {
        char c = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = c;
    }
    return str;
}


//Problem 36: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
//Evaluate the expression. Return an integer that represents the value of the expression.
int calc(int a,int b,char c) {
        if(c=='+') return a+b;
        if(c=='-') return a-b;
        if(c=='*') return a*b;
        return a/b;
    } 
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string i : tokens) {
            if(i.size()==1 && (i[0]== '+' || i[0]== '-' || i[0]== '*' || i[0]== '/')){
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                st.push(calc(a,b,i[0]));
            }
            else {
                st.push(stoi(i));
            } 
        }
        return st.top();
    }

//Problem 37: Write a function to find the longest common prefix string amongst an array of strings.
string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        while (strs[i].find(prefix) != 0) {
            prefix = prefix.substr(0, prefix.length() - 1);
        }
    }
    return prefix;
}

//Problem 37: Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
int mySqrt(int x) {
       long start=0; 
       long end=x; 
       while(start+1 < end) {
           long mid = (end + start)/2;
           if(mid * mid == x) 
            return (int)mid;
           else if(mid * mid < x) 
            start = mid;
           else 
            end = mid;
       }
       if(end * end == x )
        return (int)end;
       return (int)start;
    }


//Problem 38: Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
string removeKdigits(string num, int k) {
    if (k >= num.length()) return "0";
    deque<int>dq;

    for (int i = 0; i < num.length(); i++) {
        int curr = num[i] - '0';
        while (!dq.empty() && curr < dq.back() && k) {
            dq.pop_back();
            k--;
        }
        dq.push_back(curr);
    }
    while (!dq.empty() && dq.front()==0) {
        dq.pop_front();
    }
    while (!dq.empty() && k--) {
        dq.pop_back();
    }
    string str = "";
    while (!dq.empty())
    {
        str += dq.front() + '0';
        dq.pop_front();
    }
    if (str == "") return "0";
    return str;
}


//Problem 39: You are given an array nums of n positive integers.
//You can perform two types of operations on any element of the array any number of times:
//If the element is even, divide it by 2.
//for example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
//If the element is odd, multiply it by 2.
//For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
//The deviation of the array is the maximum difference between any two elements in the array.
//Return the minimum deviation the array can have after performing some number of operations.
int minimumDeviation(vector<int> nums) {
    set<int>st;
    for (int i = 0; i < nums.size(); i++) {
        int val=nums[i];
        if(val%2 != 0)
        {
            val *=2;
        }
        st.insert(val);
    }
    int mn=INT_MAX;
    int diff;
    while(1) {
        auto last=prev(st.end());
        auto first=st.begin();
        diff=*last - (*first);
        mn=min(mn,diff);
        if(*last%2 == 0) {
            int val=*last;
            st.erase(last);
            st.insert(val/2);
        }
        else break;
    }
    return mn;
    } 


//Problem 40: Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.
bool validateStackSequences(vector<int>pushed, vector<int>popped) {
    stack<int>st;
    int i = 0;
    int j = 0;
    while (i < pushed.size() || j < popped.size()) {
        if (!st.empty() && st.top() == popped[j]) {
            st.pop();
            j++;
        }
        else if (i >= pushed.size()) {
            return false;
        }
        else {
            st.push(pushed[i]);
            i++;
        }
    }
    return st.empty();
}

//Problem 41:Given a string s, find the length of the longest substring without repeating characters.
int lengthOfLongestSubstring(string s) {
        int mx=0;
        string str="";
        for(int i=0;i<s.length();i++) {
            while(i<s.length() && str.find(s[i])==string::npos) 
            {
                    str+=s[i];
                    i++;
            }
            int len = str.length();
            if ( len > mx)
                mx = len;
            if(i<s.length())
                str=str.substr(str.find(s[i])+1);
            i--;
        }
        return mx;
    }
//Problem 42 : Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            mp[nums[i]]++;
        }
        for(unordered_map<int,int>::iterator it = mp.begin();it!=mp.end();it++) {
            if(it->second > nums.size()/2) {
                return it->first;
            }
        }
        return 0;
    }

//Problem 43 (method 2) : Given an array nums of size n, return the majority element.
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
int majorityElementM2(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int count = 0;
    int majority_element = nums[0];
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            majority_element = nums[i];
        }
        if (nums[i] == majority_element) {
            count++;
        }
        else {
            count--;
        }
    }
    return majority_element;
}


//Problem 44 : Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
bool containsDuplicate(vector<int> nums) {
        sort(nums.begin(),nums.end());
        for(vector<int>::iterator  it=nums.begin();it != prev(nums.end());it++) {
            if(*it == *(it+1)) return true;
        }
        return false;
    }

//Problem 45 : Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
int missingNumber(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);

        int mid= nums.size() * (nums.size()+1) /2;

        return mid - sum; 
    }

//Problem 45 : Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//You must solve this problem without using the library's sort function.
void sortColors(vector<int>& nums) {
        int now=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) {
                swap(nums[now],nums[i]);
                now++;
            }
        }

        for(int i=now;i<nums.size();i++) {
            if(nums[i] == 1) {
                swap(nums[now],nums[i]);
                now++;
            }
        }

        for(int i=now;i<nums.size();i++) {
            if(nums[i] == 2) {
                swap(nums[now],nums[i]);
                now++;
            }
        }
    }

////Problem 46 : Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
vector<vector<int>> merge(vector<vector<int>> intervals) {
    int i = 0;
    sort(intervals.begin(),intervals.end());
    while (i < intervals.size() - 1) {
        if (intervals[i+1][1] < intervals[i][1])
            intervals.erase(intervals.begin() + i + 1);
        else if (intervals[i][1] >= intervals[i + 1][0]) {
            intervals[i][1] = intervals[i + 1][1];
            intervals.erase(intervals.begin() + i + 1);
        }  
        else {
            i++;
        }
    }
    return intervals;
    }

//Problem 47 : You are given a binary string s that contains at least one '1'.
//You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.
//Return a string representing the maximum odd binary number that can be created from the given combination.
string maximumOddBinaryNumber(string s) {
        string res="";
        int count =0;
        for(char& i : s) {
            if(i =='1')
                count++;
        }
        if(count==0) 
            return s;
        for(int i=1;i<count;i++) {
            res+='1';
        }
        for(int i=count;i<s.length();i++) {
            res+='0';
        }
        return res+'1';
    }

//problem 48 : Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
//Return any possible rearrangement of s or return "" if not possible.
string reorganizeString(string s) {
    vector<int>v(26, 0);
    for (char& c : s) {
       v[c - 'a']++;
    }
    priority_queue<pair<int, char>>pq;
    for (int i = 0; i < 26;i++) {
        if (v[i])
            pq.push({ v[i],'a' + i });
    }
    string ans = "";
    while (!pq.empty()) {
        pair<int, char>t = pq.top();
        pq.pop();
        if (pq.empty() && t.first>1) {
            return "";
        }
        
        ans += t.second;
        if (!pq.empty())
        {
            pair<int, char>t2 = pq.top();
            pq.pop();
            ans += t2.second;
            if (t2.first - 1) {
                t2.first--;
                pq.push(t2);
            }
        }
        if (t.first - 1) {
            t.first--;
            pq.push(t);
        }
    }
    return ans;
}

//problem 49 : Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res;
        for(int & i : nums) {
            res.push_back(pow(i,2));
        }
        sort(res.begin(),res.end());
        return res;
    }

//problem 50 : Given the head of a singly linked list, reverse the list, and return the reversed list.
ListNode* reverseListUsingRecursion(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* h2 = reverseList(head->next);
        head->next->next = head;
        head->next=prev;
        return h2;
    }

//problem 51 : Given the root of a binary tree, return the postorder traversal of its nodes' values.
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root != nullptr){
            vector<int>left=postorderTraversal(root->left);
            res.insert(res.end(),left.begin(),left.end());

            

            vector<int>right=postorderTraversal(root->right);
            res.insert(res.end(),right.begin(),right.end());

            res.push_back(root->val);
        }
        return res;
    }

//problem 52 : Given the root of a binary tree, return the preorder traversal of its nodes' values.
 vector<int> preorderTraversal(TreeNode* root) {
        vector<int>res;
        if(root != nullptr){
            res.push_back(root->val);
            
            vector<int>left=postorderTraversal(root->left);
            res.insert(res.end(),left.begin(),left.end());
            
            vector<int>right=postorderTraversal(root->right);
            res.insert(res.end(),right.begin(),right.end());
        }
        return res;
    }

//problem 53 : You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, where each tokens[i] donates the value of tokeni.
//Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in one of the two ways (but not both for the same token):
//Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
//Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
//Return the maximum possible score you can achieve after playing any number of tokens.
int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(),tokens.end());
        int maxScore = 0;
        int score = 0;
        int l=0;
        int r=tokens.size() - 1;
        while( l<=r) {
            if(power >=tokens[l]) {
                power -=tokens[l++];
                score++;
                maxScore = max(maxScore,score);
            } else if (score>0) {
                power +=tokens[r--];
                score--;
            } else break;
        }
        return maxScore;
    }

//problem 54 : Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
//Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
//Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
//The prefix and the suffix should not intersect at any index.
//The characters from the prefix and suffix must be the same.
//Delete both the prefix and the suffix.
//Return the minimum length of s after performing the above operation any number of times (possibly zero times).
int minimumLength(string s) {
        bool test=true;
        while(s.size() > 1 && test) {
            char c1=s[0];
            char c2=s[s.size()-1];
            test=false;
            while(s.size()>0 && s[0] == c2) 
            {
                test=true;
                s.erase(s.begin());
            }
            while(s.size()>0 && s[s.size()-1] == c1) 
            {
                test=true;
                s.erase(s.begin()+s.size()-1);
            }
        }
        return s.size();
    }
//problem 55 :Given an integer n, return true if it is a power of four. Otherwise, return false.
//An integer n is a power of four, if there exists an integer x such that n == 4x.
bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<1 || n%4!=0) return false;
        return isPowerOfFour(n/4); 
    }

//problem 56 : You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
//The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
//The 1st place athlete's rank is "Gold Medal".
//The 2nd place athlete's rank is "Silver Medal".
//The 3rd place athlete's rank is "Bronze Medal".
//For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
//Return an array answer of size n where answer[i] is the rank of the ith athlete. 
vector<string> findRelativeRanks(vector<int>& score) {
    priority_queue<pair<int,int>>mp;
    int n = score.size();
    for (int i = 0; i < n; i++) {
        mp.push(make_pair(score[i], i));
    }
    vector<string>res(n);
    int i = 1;
    while(!mp.empty()) {
        pair<int, int> p = mp.top();
        if (i == 1)
            res[p.second] = "Gold Medal";
        else if (i == 2)
            res[p.second] = "Silver Medal";
        else if (i == 3)
            res[p.second] = "Bronze Medal";
        else
            res[p.second] = to_string(i);
        i++;
        mp.pop();
    }
    return res;
    }

//problem 56 : Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.
bool isPowerOfTwo(int n) {
        if(n==0) return false;
        if (n==1) return true; 
        if(n%2 == 0) return isPowerOfTwo(n/2);
        return false;
}


//problem 57 : You are given a sorted unique integer array nums.
//A range [a,b] is the set of all integers from a to b (inclusive).
//Return the smallest sorted list of ranges that cover all the numbers in the array exactly. That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
//Each range [a,b] in the list should be output as:
//"a->b" if a != b
//"a" if a == b
vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        for(int i=0;i<nums.size();i++)
        {
            string s=to_string(nums[i]);
            bool entry=false;
            while(i< nums.size()-1 && nums[i]+1 == nums[i+1]) {
                i++;
                entry=true;
            }
            if(entry) {
                s+="->"+to_string(nums[i]);
            }

            res.push_back(s);
        }
        return res;
    }

//problem 58 : Given head, the head of a linked list, determine if the linked list has a cycle in it.
//There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
//Return true if there is a cycle in the linked list. Otherwise, return false.
bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next) {
            slow = slow->next;
            fast=fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }


//problem 59 : Given the head of a singly linked list, return the middle node of the linked list.
//If there are two middle nodes, return the second middle node.
int sizeList(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            count++;
            head = head->next;
        } 
        return count;
    }
    ListNode* middleNode(ListNode* head) {
        int mid = sizeList(head) / 2;
        while(mid--) {
            head=head->next;
        }
        return head;
    }

//problem 60 : You are given an array nums consisting of positive integers.
//Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
//The frequency of an element is the number of occurrences of that element in the array. 
int maxFrequencyElements(vector<int>& nums) {
       map<int,int>mp;
       int max = 0;
       int count=0;
       for(int & i:nums) {
           mp[i]++;
           if(mp[i]>max) {
               max=mp[i];
               count=1;
           }
           else if(mp[i]==max) {
               count++;
           }
       } 
       return count*max;
    }


//Problem 61 : Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
//Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(int &i:nums1) {
            mp[i]++;
        }
        for(int &i:nums2) {
            if(mp[i]>0) 
                return i;
        }
        return -1;
    }

//Problem 62 : Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//You must implement a solution with a linear runtime complexity and use only constant extra space.
int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]==nums[i+1]) i+=2;
            else 
                return nums[i] ;
        }
        return nums[nums.size()-1];
    }

//Problem 62 : Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
//You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
vector<int> singleNumber2(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>mp;
        for(int &i:nums) {
            mp[i]++;
        } 
        for(auto &i :mp){
            if(i.second == 1) {
                res.push_back(i.first);
                if(res.size()==2) return res;
            }
        }
        return res;
    }

//Problem 63 : transfert number to text 
string NumberToText(int Number) {
	if (Number == 0) {
		return"";
	}
	if (Number >= 1 && Number <= 19) {
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return  arr[Number] + " ";
	}
	if (Number >= 20 && Number <= 99) {
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return  arr[Number / 10] + " " + NumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 199) {
		return"One Hundred " + NumberToText(Number % 100);
	}
	if (Number >= 200 && Number <= 999) {
		return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 1999) {
		return"One Thousand " + NumberToText(Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999) {
		return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999) {
		return"One Million " + NumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999) {
		return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999) {
		return"One Billion " + NumberToText(Number % 1000000000);
	}
	else {
		return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
	}
}

//Problem 63 : You are given two strings order and s. All the characters of order are unique and were sorted in some custom order previously.
//Permute the characters of s so that they match the order that order was sorted. More specifically, if a character x occurs before a character y in order, then x should occur before y in the permuted string.
//Return any permutation of s that satisfies this property.
string customSortString(string order, string s) {
        map<char,int>mp;
        for(char i:s) {
            mp[i]++;
        }
        string res="";
        for(char i:order) {
                for(int j=0;j<mp[i];j++) {
                    res+=i;
                }
        }
        for(char i:s) {
            if(order.find(i) == string::npos)
                res+=i;
        }
        return res;
    }

//Problem 64 : Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.
//After doing so, return the head of the final linked list.  You may return any such answer.
//(Note that in the examples below, all sequences are serializations of ListNode objects.)    
ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* prec=nullptr;
        ListNode* curr=head;
        while(curr) {
            ListNode* tmp=curr;
            int s=0;
            bool isEntry=false;
            while(tmp) {
                s+=tmp->val;
                if(s==0) {
                    isEntry=true;
                    if(prec==nullptr) {
                        head=tmp->next;
                        curr=head;
                    } else {
                       curr=prec;
                       curr->next=tmp->next; 
                    }
                    break;
                }
                tmp=tmp->next;
            }
            if(!isEntry) {
                prec=curr;
                curr=curr->next;
            }
        }
        return head;
}

//Problem 65 : Given a positive integer n, find the pivot integer x such that:
//The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
//Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.
int pivotInteger(int n) {
        if(n==1) return n;
        int s=(n*(n+1))/2;
        for(int i=n/2;i<n;i++) {
            int sum1ToX=(i*(i+1))/2;
            int sumXToN=s-sum1ToX+i;
            if(sum1ToX == sumXToN) 
                return i;
        }
        return -1;
}

//Problem 66 : Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//You must write an algorithm that runs in O(n) time and without using the division operation.
vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        int prefix = 1;
        for(int i=0; i<nums.size(); i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i=nums.size()-1; i>=0; i--) { // iterate in reverse
            answer[i] *= postfix; // dont replace the old prefix value
            postfix *= nums[i];
        }
        return answer;
    }

//Problem 67 : You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
//Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
//Return intervals after the insertion.
//Note that you don't need to modify intervals in-place. You can make a new array and return it
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0;
    while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i++]);
    }
    while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        ++i;
    }
    res.push_back(newInterval);
    
    while (i < intervals.size()) {
        res.push_back(intervals[i++]);
    }

    return res;
}


//Problem 68 : You are given two linked lists: list1 and list2 of sizes n and m respectively.
//Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode* lastNodeList2 = list2;
    while (lastNodeList2->next) {
        lastNodeList2 = lastNodeList2->next;
    }
    ListNode* tmp1 = list1;
    b = b - a+3;
    while (--a && tmp1) {
        tmp1 = tmp1->next;
    }
    ListNode* tmp2 = tmp1;
   
    while (--b && tmp2) {
        tmp2 = tmp2->next;
    }
    tmp1->next = list2;
    lastNodeList2->next = tmp2;
    return list1;
}

//Problem 70 : You are given the head of a singly linked-list. The list can be represented as:
//L0 → L1 → … → Ln - 1 → Ln
//Reorder the list to be on the following form:
//L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
void reorderList(ListNode* head) {
        ListNode* tmp=head;
        vector<int>v1;
        while(tmp != nullptr) {
            v1.push_back(tmp->val);
            tmp=tmp->next;
        }

        tmp=head;
        int i=0;
        int j=v1.size()-1;
        bool test=true;
        while(tmp != nullptr) {
            if(test) {
                tmp->val=v1[i];
                i++;
                test=false;
            } else {
                tmp->val=v1[j];
                j--;
                test=true;
            }
            tmp=tmp->next;
        }
    }

//Problem 71 : You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//Merge all the linked-lists into one sorted linked-list and return it.
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
        return nullptr;
    }

    multiset<int , greater<int>>mst;
    for (int i = 0; i < lists.size(); i++) {
        while (lists[i] != nullptr) {
            mst.insert(lists[i]->val);
            lists[i] = lists[i]->next;
        }
    }
    ListNode* ans = nullptr;
    for (multiset<int>::iterator it = mst.begin(); it != mst.end(); it++) {
        ListNode* newNode = new ListNode(*it, ans);
        ans = newNode;
    }
    return ans;
}

//Problem 72 : Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
bool isPalindrome(ListNode* head) {
    ListNode* rev = nullptr;
    for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
        ListNode* newNode = new ListNode(tmp->val, rev);
        rev = newNode;
    }

    for (head,rev ; head != nullptr; head = head->next , rev=rev->next) {
        if (rev->val != head->val) return false;
    }
    return true;
}

//Problem 73 : Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
//You must write an algorithm that runs in O(n) time and uses only constant extra space.
vector<int> findDuplicates(vector<int>& nums) {
        int arr[100001]={0};
        vector<int>ans;
        for(int i:nums) {
            arr[i]++;
            if(arr[i]==2) {
                ans.push_back(i);
            }
        }
        return ans;
    }

//Problem 74 : Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
//You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.
int firstMissingPositive(vector<int> nums) {
    set<int> m;
    for (int i : nums) {
        if (i > 0)
            m.insert(i);
    }
    int val = 1;
    for (auto i : m) {
        if (val != i) {
            return val;
        }
        else
            val++;
    }
    return val;
   }

////Problem 75 : Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int count = 0;
        for(int i=0;i<n;i++) {
            int s=1;
            for(int j=i;j<n;j++) {
                s*=nums[j];
                if(s<k) count++;
                else
                break;
            }
        }
        return count;
}

//Problem 76 : You are given an integer array nums and an integer k.
//The frequency of an element x is the number of times it occurs in an array.
//An array is called good if the frequency of each element in this array is less than or equal to k.
//Return the length of the longest good subarray of nums.
//A subarray is a contiguous non-empty sequence of elements within an array.
int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int n=nums.size();
        int ans = 1;
        int j=0;
        int i=0;
        while(i<n && j<n) {
            mp[nums[j]]++;
            while (mp[nums[j]]>k) {
                mp[nums[i]]--;
                i++;
            }
            ans = max(j-i+1, ans);
            j++;
        }
            
        return ans;
    
    }

//Problem 78 : You are given an integer array nums and a positive integer k.
//Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
//A subarray is a contiguous sequence of elements within an array.
long long countSubarrays(vector<int> &nums, int k) {
        int mx = -1;
        int n = nums.size();
        for (int i :nums) {
            mx = max(mx, i);
        }
        long long count = 0;
        unordered_map<int, int>mp;
        int i = 0, j = 0;
        while (j < n) {
            mp[nums[j]]++;
            while (mp[mx] >= k) {
                count += n - j;
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }


//Problem 79 : Given an integer array nums and an integer k, return the number of good subarrays of nums.
//A good array is an array where the number of different integers in that array is exactly k.
//For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
//A subarray is a contiguous part of an array.
int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq;
    int left = 0, right = 0;
    int goodSubarrays = 0;
    int distinctCount = 0;

    while (right < n) {
        if (freq[nums[right]] == 0)
            distinctCount++;
        
        freq[nums[right]]++;

        while (distinctCount > k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                distinctCount--;
            left++;
        }

        goodSubarrays += right - left + 1;

        right++;
    }

    left = 0;
    right = 0;
    distinctCount = 0;
    freq.clear();

    while (right < n) {
        if (freq[nums[right]] == 0)
            distinctCount++;
        
        freq[nums[right]]++;

        while (distinctCount >= k) {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
                distinctCount--;
            left++;
        }

        goodSubarrays -= right - left + 1;

        right++;
    }

    return goodSubarrays;
}
//Problem 81 : Given two strings s and t, determine if they are isomorphic.
//Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
bool isIsomorphic(string t, string s) {
       if(s.length() != t.length()) return false;
       map<char,char>mp;
       map<char,char>mp2;
       for(int i=0;i<t.length();i++) {
           map<char,char>::iterator it = mp.find(s[i]);
           map<char,char>::iterator it2 = mp2.find(t[i]);
           if(it != mp.end()) {
           if(mp[s[i]] != t[i])
               return false;
           } else {
            mp.insert(make_pair(s[i],t[i]));
           }

           if(it2 != mp2.end()) {
           if(mp2[t[i]] != s[i])
               return false;
           } else {
            mp2.insert(make_pair(t[i],s[i]));
           }
       }
       return true;
    }

//problem 82 : 1614. Maximum Nesting Depth of the Parentheses
int maxDepth(string s) {
        int mx=0;
        int count=0;
        for(char c : s ) {
            if(c == '(') {
                count++;
                mx=max(count,mx);
            } else if(c == ')')
                count--;
        }
        return mx;
    }

//problem 83 : Given a string s of lower and upper case English letters.
//A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where: 0 <= i <= s.length - 2
//s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
//To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.
//Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
//Notice that an empty string is also good.
string makeGood(string s) {
        int i = 0;
        while (!s.empty() && i < s.size() - 1) {
            if (int(s[i]) == int(s[i + 1]) + 32 || int(s[i]) == int(s[i + 1]) - 32) {
                s = s.substr(0, i) + s.substr(i + 2);
                if (i > 0)i--;
            }
            else
                i++;
        }
        return s;
}

//Problem 84 : Given a string s of '(' , ')' and lowercase English characters.
//Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.
//Formally, a parentheses string is valid if and only if:
//It is the empty string, contains only lowercase characters, or
//It can be written as AB (A concatenated with B), where A and B are valid strings, or
//It can be written as (A), where A is a valid string

string minRemoveToMakeValid(string ch) {
        int count = 0 ; 
        for(int i=0;i<ch.length();i++) {
            if(ch[i] == '(') {
                count++;
            } else if(ch[i] ==')') {
                if(count>0) {
                    count--;
                } else {
                    ch[i]='*';
                } 
            }
        }

        count = 0 ; 
        for(int i=ch.length()-1;i>=0;i--) {
            if(ch[i] == ')') {
                count++;
            } else if(ch[i] =='(') {
                if(count>0) {
                    count--;
                } else {
                    ch[i]='*';
                } 
            }
        }

        string ans="";
        for(char c : ch) {
            if(c!='*')
                ans+=c;
        }
        return ans;
    }

//Problem 85 : leetcode 1700. Number of Students Unable to Eat Lunch
int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zeros=0,ones=0;
        for(int i : students) {
            if(i==0) zeros++;
            else ones++;
        }
        for(int i :sandwiches) {
            if(i == 0) {
                if(zeros > 0) zeros--;
                else return ones;
            }
            else if(i == 1) {
                if(ones > 0) ones--;
                else return zeros;
            }
        }
        return 0;
    }

//Problem 86 : 2073. Time Needed to Buy Tickets
int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int count=0;
        for(int i=0;i<n;i++) {
            if(i<k) {
                if(tickets[i]<=tickets[k]) {
                    count+=tickets[i];
                } else 
                    count+=tickets[k];
            }else if(i==k) {
                count+=tickets[k];
            } else {
                if(tickets[i]<tickets[k]) {
                    count+=tickets[i];
                } else 
                    count+=tickets[k]-1;
            }
        }
        return count;
    }

//Problem 87 : Write a function that takes the binary representation of a positive integer and returns the number of  set bits it has (also known as the Hamming weight).
int hammingWeight(int n) {
        long long val=1;
        while(val<=n) {
            val*=2;
        }
        int count=0;
        while(n > 0) {
            val/=2;
            if(val<=n) {
                n-=val;
                count++;
            }
        }
        return count;
    }

//Problem 88 : Given the root of a binary tree, return the sum of all left leaves.
//A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        else if(root->left != nullptr && root->left->left == nullptr && root->left->right==nullptr) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return  sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

//Problem 89 : You are given the root of a binary tree containing digits from 0 to 9 only.
//Each root-to-leaf path in the tree represents a number.
//For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
//Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
//A leaf node is a node with no children.
void sumNum(TreeNode* root,string s,int &sum) {
        if(root!=nullptr) {
            
            if(root->left==nullptr && root->right==nullptr) {
                string r=s + char(root->val + '0');
                sum+=stoi(r);
            } else
            {
                s+=root->val + '0';
                sumNum(root->left,s,sum);
                sumNum(root->right,s,sum);
            }
        }
    }
int sumNumbers(TreeNode* root) {
        int sum=0;
        string s="";
        sumNum(root,s,sum);
        return sum;
    }

//problem 91 : You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
//Letters are case sensitive, so "a" is considered a different type of stone from "A".
int numJewelsInStones(string jewels, string stones) {
       unordered_map<char,bool>mpj;
       for(char c : jewels) {
            mpj[c]=true;
       } 
       int count=0;
       for(char c : stones) {
            if(mpj[c]) {
                count++;
            }
       } 
       return count;
    }

//Problem 91: You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
//Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
//The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
int islandPerimeter(vector<vector<int>>& grid) {
        int lines=grid.size(),cols=grid[0].size();
        int ans=0;
        for(int i=0;i<lines;i++) {
            for(int j=0;j<cols;j++) {
                int sum=4;
                if(grid[i][j]==1) {
                    if(i>0 && grid[i-1][j]==1) {
                        sum--;
                    }
                    if(j>0 && grid[i][j-1]==1) {
                        sum--;
                    }

                    if(i<lines-1 && grid[i+1][j]==1) {
                        sum--;
                    }
                    if(j<cols-1 && grid[i][j+1]==1) {
                        sum--;
                    }
                    ans+=sum;
                }
            }
         
        }
        return ans;
    }

//problem 92: Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
    void tests(vector<vector<char>>& grid,int x,int y,int rows,int cols) {
        if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y] != '1')
            return;
        grid[x][y]='2';
        tests(grid,x-1,y,rows,cols); 
        tests(grid,x,y-1,rows,cols); 
        tests(grid,x+1,y,rows,cols); 
        tests(grid,x,y+1,rows,cols); 
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int ans=0;
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(grid[i][j]=='1') {
                    ans++;
                    tests(grid,i,j,rows,cols);
                }
            }
        }
        return ans;
    }
//problem 93: The Tribonacci sequence Tn is defined as follows: T0 = 0, T1 = 1, T2 = 1, and Tn + 3 = Tn + Tn + 1 + Tn + 2 for n >= 0.
//Given n, return the value of Tn.
   int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int ans = 0;
        int prev1 = 1;
        int prev2 = 1;
        int prev3 = 0;
        for (int i = 2; i < n; i++) {
            ans = prev1 + prev3 + prev2;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }

//problem 93: Given the root of a binary tree, return its maximum depth.
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
   int maxDepth(TreeNode* root) {
       
       if (root == nullptr)
           return 0;
       return
           1 + max(maxDepth(root->left), maxDepth(root->right));
   }

// problem 94: Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
// The interval[a, b) is covered by the interval[c, d) if and only if c <= a and b <= d.
// Return the number of remaining intervals.
   int removeCoveredIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return  a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
       int ans = intervals.size();
       int curr = -1;
       for (int i = 0; i < intervals.size(); i++) {
           if (intervals[i][1] <= curr)
               ans--;
           else
               curr = intervals[i][1];
       }
       return ans;
   }

// problem 95:  Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.
// For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive).The resulting string will be "dcbaefd".
// Return the resulting string.
   string reversePrefix(string word, char ch) {
       string str1 = "";
       int i = 0;
       for (i = 0; i < word.size(); i++) {
           str1 = word[i] + str1;
           if (word[i] == ch) {
               break;
           }
       }
       if (i >= word.size())
           return word;
       word = word.substr(i + 1);
       str1 += word;
       return str1;
   }
//problem 96: Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.
   int titleToNumber(string columnTitle) {
       int n = columnTitle.size() - 1;
       int ans = 0;
       for (int i = 0; i < columnTitle.size(); i++) {
           ans += (columnTitle[i] - 64) * pow(26, n--);
       }
       return ans;
   }

//problem 97: Given the head of a linked list, return the list after sorting it in ascending order.
   ListNode* sortList(ListNode* head) {
       multiset<int>st;
       for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
           st.insert(tmp->val);
       }
       ListNode* tmp = head;
       for (auto it = st.begin(); it != st.end(); it++) {
           tmp->val = *it;
           tmp = tmp->next;
       }
       return head;
   }

//problem 98: Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
//Return the positive integer k.If there is no such integer, return -1.
   int findMaxK(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       for (int i = nums.size() - 1; i >= 0 && nums[i] > 0; i--) {
           if (find(nums.begin(), nums.end(), -(nums[i])) != nums.end())
               return nums[i];
       }
       return -1;
   }
//problem 99: You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
//Return the minimum number of boats to carry every given person.
   int numRescueBoats(vector<int>& people, int limit) {
       int bots = 0;
       int i = 0;
       int n = people.size();
       int j = n - 1;
       sort(people.begin(), people.end());
       while (true) {
           if (j <= i)
               return (bots + n - i);
           if (people[i] + people[j] <= limit) {
               bots += n - j;
               n = j;
               j--;
               i++;
           }
           else
               j--;
       }
       return bots;
   }

//problem 99 : Given two version numbers, version1 and version2, compare them. Version numbers consist of one or more revisions joined by a dot '.'.Each revision consists of digits and may contain leading zeros.Every revision contains at least one character.Revisions are 0 - indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on.For example 2.5.33 and 0.1 are valid version numbers. To compare version numbers, compare their revisions in left - to - right order.Revisions are compared using their integer value ignoring any leading zeros.This means that revisions 1 and 001 are considered equal.If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
// Return the following :
//If version1 < version2, return -1. If version1 > version2, return 1. Otherwise, return 0.
   int compareVersion(string version1, string version2) {
       int i = 0, j = 0;

       while (i < version1.size() || j < version2.size()) {
           int num1 = 0, num2 = 0;
           while (i < version1.size() && version1[i] != '.') {
               num1 = num1 * 10 + (version1[i] - '0');
               i++;
           }

           while (j < version2.size() && version2[j] != '.') {
               num2 = num2 * 10 + (version2[j] - '0');
               j++;
           }

           if (num1 < num2) return -1;
           else if (num1 > num2) return 1;

           i++;
           j++;
       }
       return 0;

//problem 100 : check is last day in month ?
       bool isLeapYear(int year) {
           if (year % 4 == 0) {
               if (year % 100 == 0) {
                   if (year % 400 == 0) {
                       return true;
                   }
                   else {
                       return false;
                   }
               }
               else {
                   return true;
               }
           }
           else {
               return false;
           }
       }

       int numberOfDaysInMonth(int month, int year) {
           if (month < 1 || month < 12)
               return 0;
           int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

           if (isLeapYear(year))
               months[1]++;

           return months[month - 1];
       }

       bool isLastDayInMonth(int day, int month, int year) {
           return(day == numberOfDaysInMonth(month, year));
       }

       bool isLastMonthInYear(int month) {
           return (month == 12);

}

//problem 101 : increase date by one day 
       struct stDate
       {
           int day, month, year;
       };
       void increaseDateByOneDay(stDate date) {
           if (isLastDayInMonth(date.day, date.month, date.year)) {
               if (isLastMonthInYear(date.month)) {
                   date.year++;
                   date.month = 1;
               }
               else
                   date.month++;

               date.day = 1;
           }
           else
               date.day++;
       }

// problem 102 : Leetcode 237. Delete Node in a Linked List
       void deleteNode(ListNode* node) {
           while (node->next) {
               node->val = node->next->val;
               if (!node->next->next) {
                   node->next = nullptr;
               }
               else
                   node = node->next;
           }
       }      

// problem 103 : You are given the head of a linked list ,Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list. 237. Delete Node in a Linked List
   ListNode* removeNodes(ListNode* head) {
           head = reverseList(head);
           ListNode* curr = head->next;
           ListNode* prev = head;
           while (curr) {
               if (curr->val < prev->val) {
                   curr = curr->next;
                   delete prev->next;
                   prev->next = curr;
               }
               else
               {
                   prev = curr;
                   curr = curr->next;
               }
           }
           return reverseList(head);
       }
//problem 104 : Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//A subsequence of a string is a new string that is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
   bool isSubsequence(string sub, string orig) {
       if (orig.length() < sub.length())
           return false;
       int i = 0;
       int j = 0;
       while (i < orig.length() && j < sub.size()) {
           if (orig[i] == sub[j]) {
               j++;
           }
           i++;
       }
       if (j >= sub.size())
           return true;
       return false;
   }

//Problem 105 : An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//For example, [1, 3, 5, 7, 9], [7, 7, 7, 7], and [3, -1, -5, -9] are arithmetic sequences. Given an integer array nums, return the number of arithmetic subarrays of nums. A subarray is a contiguous subsequence of the array.
   int numberOfArithmeticSlices(vector<int>& nums) {
       if (nums.size() < 3)
           return 0;
       int sum = 0;
       int count = 0;
       int diff = nums[1] - nums[0];
       for (int i = 2; i < nums.size(); i++) {
           if (nums[i] - nums[i - 1] == diff) {
               count++;
           }
           else {
               count = 0;
               diff = nums[i] - nums[i - 1];
           }
           sum += count;
       }
       return sum;
   }

// Problem 106 : You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.
// Return the head of the linked list after doubling it.
   ListNode* doubleIt(ListNode* head) {
       string str = "";
       ListNode* tmp = head;
       while (tmp) {
           str += (tmp->val + 48);
           tmp = tmp->next;
       }
       int rest = 0;
       for (int i = str.length() - 1; i >= 0; i--) {
           int val = (str[i] - '0');
           val = (val * 2) + rest;
           rest = val / 10;
           if (rest > 0) {
               val = val % 10;
           }
           str[i] = (val + 48);
       }
       if (rest > 0) {
           str = "1" + str;
       }
       tmp = head;
       ListNode* prev = nullptr;
       int i = 0;
       while (i < str.length()) {
           tmp->val = (str[i] - '0');
           prev = tmp;
           tmp = tmp->next;
           if (tmp == nullptr && i + 1 < str.size()) {
               tmp = new ListNode(str[++i] - 48);
               prev->next = tmp;
               break;
           }
           i++;
       }
       return head;
   }

//problem 107 : You are given an array happiness of length n, and a positive integer k.
//There are n children standing in a queue, where the ith child has happiness value happiness[i].You want to select k children from these n children in k turns.
//In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.
//Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
   long long maximumHappinessSum(vector<int>& happiness, int k) {
       sort(happiness.begin(), happiness.end(), greater<int>());
       long long sum = 0;
       for (int i = 0; i < k; i++) {
           happiness[i] = max(0, happiness[i] - i);
           sum += happiness[i];
       }
       return sum;
   }
//problem 108 : You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
//For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
//Return the kth smallest fraction considered.Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].
   vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
       int n = arr.size();
       double left = 0, right = 1, mid;
       vector<int> res;

       while (left <= right) {
           mid = left + (right - left) / 2;
           int j = 1, total = 0, num = 0, den = 0;
           double maxFrac = 0;
           for (int i = 0; i < n; ++i) {
               while (j < n && arr[i] >= arr[j] * mid) {
                   ++j;
               }

               total += n - j;

               if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
                   maxFrac = arr[i] * 1.0 / arr[j];
                   num = i; den = j;
               }
           }

           if (total == k) {
               res = { arr[num], arr[den] };
               break;
           }

           if (total > k) {
               right = mid;
           }
           else {
               left = mid;
           }
       }

       return res;
   }

   // problem 109 : You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.
   // For example, given num = 2932, you have the following digits : two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
   // Return the minimum possible sum of new1 and new2.
   // 1000 <= num <= 9999
   int minimumSum(int num) {
       vector<int>v;
       while (num > 9) {
           v.push_back(num % 10);
           num /= 10;
       }
       v.push_back(num);
       sort(v.begin(), v.end());
       int n1 = 0;
       int n2 = 0;
       n1 = n1 * 10 + v[0];
       n1 = n1 * 10 + v[2];
       n2 = n2 * 10 + v[1];
       n2 = n2 * 10 + v[3];
       return n1 + n2;
   }

   // problem 110 : Balanced strings are those that have an equal quantity of 'L' and 'R' characters. Given a balanced string s, split it into some number of substrings such that : Each substring is balanced
   // Return the maximum number of balanced strings you can obtain.
   int balancedStringSplit(string s) {
       int L = 0, ans = 0;
       for (char i : s) {
           if (i == 'L')
               L++;
           else
               L--;
           if (L == 0)
               ans++;
       }
       return ans;
   }

   // problem 111 : You are given a positive integer num consisting only of digits 6 and 9.
   // Return the maximum number you can get by changing at most one digit(6 becomes 9, and 9 becomes 6).
   int maximum69Number(int num) {
       string str = to_string(num);
       int max = num;
       for (int i = 0; i < str.size(); i++) {
           if (str[i] == '6') {
               str[i] = '9';
               int val = stoi(str);
               if (val > max)
                   max = val;
               str[i] = '6';
           }
       }
       return max;
   }

   // problem 112 : You are given an n x n integer matrix grid. Generate an integer matrix maxLocal of size(n - 2) x(n - 2) such that : maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1. In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
   // Return the generated matrix.
   vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
       int n = grid.size();
       vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
       for (int i = 0; i < n - 2; i++) {
           for (int j = 0; j < n - 2; j++) {
               int mx = grid[i][j];
               for (int s = i; s < i + 3; s++) {
                   for (int k = j; k < j + 3; k++) {
                       mx = max(grid[s][k], mx);
                   }
               }
               ans[i][j] = mx;
           }
       }
       return ans;
   }

   // problem 113 : In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.
   // Return the maximum amount of gold you can collect under the conditions :
   // Every time you are located in a cell you will collect all the gold in that cell. From your position, you can walk one step to the left, right, up, or down. You can't visit the same cell more than once. Never visit a cell with 0 gold. You can start and stop collecting gold from any position in the grid that has some gold.
   void solveMaxGold(vector<vector<int>>& grid, int i, int j, int n, int m, int sum, int& mx, vector<vector<bool>>& used) {
       if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || used[i][j]) {
           return;
       }

       sum += grid[i][j];
       used[i][j] = true;
       mx = max(mx, sum);

       solveMaxGold(grid, i - 1, j, n, m, sum, mx, used);
       solveMaxGold(grid, i + 1, j, n, m, sum, mx, used);
       solveMaxGold(grid, i, j - 1, n, m, sum, mx, used);
       solveMaxGold(grid, i, j + 1, n, m, sum, mx, used);

       used[i][j] = false;
   }

   int getMaximumGold(vector<vector<int>>& grid) {
       int mx = 0;
       int n = grid.size();
       int m = grid[0].size();

       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               if (grid[i][j] != 0) {
                   vector<vector<bool>> used(n, vector<bool>(m, false));
                   solveMaxGold(grid, i, j, n, m, 0, mx, used);
               }
           }
       }

       return mx;
   }

   // problem 114 : Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.
   // The graph is given as follows : graph[i] is a list of all nodes you can visit from node i(i.e., there is a directed edge from node i to node graph[i][j]).
   void dfs(vector<vector<int>> graph, int pos, vector<int>v, vector<vector<int>>& ans) {
       for (int i = 0; i < graph[pos].size(); i++) {
           v.push_back(graph[pos][i]);
           if (graph[pos][i] == graph.size() - 1) {
               ans.push_back(v);
           }
           else
               dfs(graph, graph[pos][i], v, ans);
           v.pop_back();
       }
       return;
   }
   vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<int>v;
       v.push_back(0);
       vector<vector<int>> ans;
       dfs(graph, 0, v, ans);
       return ans;
   }

   // problem 115 : You are given the root of a full binary tree with the following properties:
   // Leaf nodes have either the value 0 or 1, where 0 represents False and 1 represents True Non - leaf nodes have either the value 2 or 3, where 2 represents the boolean OR and 3 represents the boolean AND.The evaluation of a node is as follows : If the node is a leaf node, the evaluation is the value of the node, i.e.True or False. Otherwise, evaluate the node's two children and apply the boolean operation of its value with the children's evaluations.
   // Return the boolean result of evaluating the root node
   // A full binary tree is a binary tree where each node has either 0 or 2 children. A leaf node is a node that has zero children.
   bool evaluateTree(TreeNode* root) {
       if (root->val == 1)
           return true;
       if (root->val == 0)
           return false;
       if (root->val == 2)
           return evaluateTree(root->left) || evaluateTree(root->right);

       if (root->val == 3)
           return evaluateTree(root->left) && evaluateTree(root->right);
       return true;
   }

   // problem 116 : Given a binary tree root and an integer target, delete all the leaf nodes with value target.
   // Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted(you need to continue doing that until you cannot).
   void solveRemoveLeafNodes(bool left, bool right, TreeNode* parent, TreeNode* root, int target) {
       if (root != nullptr) {
           solveRemoveLeafNodes(true, false, root, root->left, target);
           solveRemoveLeafNodes(false, true, root, root->right, target);
           if (root->left == nullptr && root->right == nullptr && root->val == target) {
               if (parent != nullptr) {
                   if (left)
                       parent->left = nullptr;
                   else
                       parent->right = nullptr;
                   delete root;
               }
           }
       }
   }
   TreeNode* removeLeafNodes(TreeNode* root, int target) {
       solveRemoveLeafNodes(false, false, nullptr, root, target);
       if (root->left == nullptr && root->right == nullptr && root->val == target) {
           return nullptr;
       }

       return root;
   }

   //  problem 117 : Given the root of a binary tree, return the sum of values of its deepest leaves.
   void dfsManip(TreeNode* root, int& val, int& max, int& sum) {
       if (root != nullptr) {
           val++;
           if (val > max) {
               sum = root->val;
               max = val;
           }
           else if (val == max) {
               sum += root->val;
           }
           dfsManip(root->left, val, max, sum);

           dfsManip(root->right, val, max, sum);
           val--;
       }
   }

   int deepestLeavesSum(TreeNode* root) {
       int sum = 0;
       int val = 0;
       int max = 0;
       dfsManip(root, val, max, sum);
       return sum;
   }

   // problem 118 : Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
   // Note : The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer. A subtree of root is a tree consisting of root and all of its descendants.
   int sumAndLenTree(TreeNode* root, int& len) {
       if (root != nullptr) {
           len++;
           return root->val + sumAndLenTree(root->left, len) + sumAndLenTree(root->right, len);
       }
       else
           return 0;

   }
   void dfsAverageOfSubtree(TreeNode* root, vector<TreeNode*>& v) {
       if (root != nullptr) {
           v.push_back(root);
           dfsAverageOfSubtree(root->left, v);
           dfsAverageOfSubtree(root->right, v);
       }
   }
   int averageOfSubtree(TreeNode* root) {
       vector<TreeNode*>v;
       dfsAverageOfSubtree(root, v);
       int count = 0;
       for (TreeNode* it : v) {
           int len = 0;
           int sum = sumAndLenTree(it, len);
           if (sum / len == it->val)
               count++;
       }
       return count;
   }

   // problem 119 : Given an integer array nums of unique elements, return all possible 
   // subsets (the power set). The solution set must not contain duplicate subsets.Return the solution in any order.
   vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       ans.push_back({});

       for (int i : nums) {
           vector<vector<int>>newSubsts;
           for (vector<int> j : ans) {
               vector<int>v = j;
               j.push_back(i);
               newSubsts.push_back(j);
           }
           for (vector<int> j : newSubsts) {
               ans.push_back(j);
           }
       }
       return ans;
   }

   // problem 120 : You have n  tiles, where each tile has one letter tiles[i] printed on it. 
   // Return the number of possible non - empty sequences of letters you can make using the letters printed on those tiles.
   void backtraking1079(string tiles, vector<bool>& used, string& s, set<string>& res) {
       if (s != "") {
           res.insert(s);
       }
       for (int i = 0; i < tiles.size(); i++) {
           if (used[i] == 0) {
               used[i] = 1;
               s.push_back(tiles[i]);
               backtraking1079(tiles, used, s, res);
               s.pop_back();
               used[i] = 0;
           }
       }
   }

   int numTilePossibilities(string tiles) {
       vector<bool>used(tiles.size(), false);
       string s = "";
       set<string>res;
       backtraking1079(tiles, used, s, res);
       return res.size();
   }

   // problem 121 : Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
   void backtraking46(vector<int>nums, vector<bool>used, vector<int>& v, vector<vector<int>>& ans) {
       if (v.size() == nums.size()) {
           ans.push_back(v);
       }
       for (int i = 0; i < nums.size(); i++) {
           if (!used[i]) {
               used[i] = true;
               v.push_back(nums[i]);
               backtraking46(nums, used, v, ans);
               used[i] = false;
               v.pop_back();
           }
       }
   }
   vector<vector<int>> permute(vector<int>& nums) {
       vector<bool>used(nums.size(), false);
       vector<int>v;
       vector<vector<int>>ans;
       backtraking46(nums, used, v, ans);
       return ans;
   }


   void backtraking47(vector<int>nums, vector<bool>used, vector<int>& v, set<vector<int>>& ans) {
       if (v.size() == nums.size()) {
           ans.insert(v);
       }
       for (int i = 0; i < nums.size(); i++) {
           if (!used[i]) {
               used[i] = true;
               v.push_back(nums[i]);
               backtraking46(nums, used, v, ans);
               used[i] = false;
               v.pop_back();
           }
       }
   }

    //problem 122 : Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
   vector<vector<int>> permuteUnique(vector<int>& nums) {
       vector<bool>used(nums.size(), false);
       vector<int>v;
       set<vector<int>>res;
       backtraking46(nums, used, v, res);
       vector<vector<int>> ans(res.begin(), res.end());
       return ans;
   }

   // problem 123 : Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
   // If the current number is even, you have to divide it by 2. If the current number is odd, you have to add 1 to it. It is guaranteed that you can always reach one for all test cases.
   void divideByTwo(string& s) {
       s.pop_back();
   }

   void addOne(string& s) {
       int i = s.size() - 1;
       while (i >= 0 && s[i] != '0') {
           s[i] = '0';
           i--;
       }
       if (i < 0) {
           s = '1' + s;
       }
       else {
           s[i] = '1';
       }
   }

   int numSteps(string s) {
       int N = s.size();

       int operations = 0;
       while (s.size() > 1) {
           N = s.size();

           if (s[N - 1] == '0') {
               divideByTwo(s);
           }
           else {
               addOne(s);
           }

           operations++;
       }

       return operations;
   }

   // problem 124 : Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.You can return the answer in any order.
   // You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
   vector<int> singleNumber3(vector<int>& nums) {
       vector<int> ans;
       int n = nums.size();
       sort(nums.begin(), nums.end());
       for (int i = 0; i < n - 1; i++) {
           if (nums[i] != nums[i + 1])
               ans.push_back(nums[i]);
           else
               i++;
       }
       if (nums[n - 1] != nums[n - 2])
           ans.push_back(nums[n - 1]);
       return ans;
   }


   // problem 125 : You are given a string moves of length n consisting only of characters 'L', 'R', and '_'. The string represents your movement on a number line starting from the origin 0.
   // In the ith move, you can choose one of the following directions : move to the left if moves[i] = 'L' or moves[i] = '_' , move to the right if moves[i] = 'R' or moves[i] = '_' 
   // Return the distance from the origin of the furthest point you can get to after n moves.
   int furthestDistanceFromOrigin(string moves) {
       int count_ = 0;
       int distance = 0;
       for (char& c : moves) {
           if (c == 'L')
               distance--;
           else if (c == 'R')
               distance++;
           else
               count_++;
       }
       if (distance < 0)
           distance += -count_;
       else
           distance += count_;
       return abs(distance);
   }


   // problem 126 : You are given an integer array pref of size n. Find and return the array arr of size n that satisfies:
   // pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i].
   // Note that ^ denotes the bitwise - xor operation. It can be proven that the answer is unique.
   vector<int> findArray(vector<int>& pref) {
       vector<int>ans;
       ans.push_back(pref[0]);
       for (int i = 1; i < pref.size(); i++) {
           ans.push_back(pref[i] ^ pref[i - 1]);
       }
       return ans;
   }


   // problem 127 : You are given a string s.The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
   // Return the score of s.
   int scoreOfString(string s) {
       int sum = 0;
       for (int i = 0; i < s.size() - 1; i++) {
           sum += abs(s[i] - s[i + 1]);
       }
       return sum;
   }

   // problem 128 : Write a function that reverses a string. The input string is given as an array of characters s. You must do this by modifying the input array in - place with O(1) extra memory.
   void reverseString(vector<char>& s) {
       for (int i = 0; i < s.size() / 2; i++) {
           swap(s[i], s[s.size() - i - 1]);
       }
   }

   // problem 129 : There are n teams numbered from 0 to n - 1 in a tournament.
   // Given a 0 - indexed 2D boolean matrix grid of size n * n.For all i, j that 0 <= i, j <= n - 1 and i != j team i is stronger than team j if grid[i][j] == 1, otherwise, team j is stronger than team i.
   // Team a will be the champion of the tournament if there is no team b that is stronger than team a.
   // Return the team that will be the champion of the tournament.
   int findChampion1(vector<vector<int>>& grid) {
       int n = grid.size();
       int mx = 0;
       int team = 0;
       for (int i = 0; i < n; i++) {
           int count = 0;
           for (int j = 0; j < n; j++) {
               if (i != j && grid[i][j] == 1) {
                   count++;
               }
           }
           if (count > mx) {
               team = i;
               mx = count;
           }
       }
       return team;
   }


   // problem 130 : There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.
   // You are given the integer n and a 0 - indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.
   // A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.
   // Team a will be the champion of the tournament if there is no team b that is stronger than team a.
   // Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.
   int findChampion2(int n, vector<vector<int>>& edges) {
       vector<int>v(n);
       for (int i = 0; i < n; i++) {
           v[i] = i;
       }
       for (int i = 0; i < edges.size(); i++) {
           if (v[edges[i][1]] = -1);
       }
       int ans = -1;
       for (int i = 0; i < n; i++) {
           if (v[i] != -1)
               if (ans != -1)
                   return -1;
               else
                   ans = v[i];
       }
       return ans;
   }

   // problem 131 : Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
   ListNode* deleteDuplicates2(ListNode* head) {
       ListNode* tmp = head;
       ListNode* prev = nullptr;
       while (tmp) {
           int val = tmp->val;
           if (tmp->next && tmp->next->val == val) {
               while (tmp && tmp->val == val) {
                   ListNode* curr = tmp;
                   tmp = tmp->next;
                   delete curr;
               }
               if (prev == nullptr) {
                   head = tmp;
               }
               else {
                   prev->next = tmp;
               }
           }
           else {
               prev = tmp;
               tmp = tmp->next;
           }
       }
       return head;
   }

   //problem 132 : Given the head of a linked list, rotate the list to the right by k places.
   ListNode* rotateRight(ListNode* head, int k) {
       if (head == nullptr || head->next == nullptr || k == 0) {
           return head;
       }
       int size = 0;
       for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
           size++;
       }
       if (k >= size) {
           k %= size;
       }
       if (k == 0) {
           return head;
       }

       k = size - k;
       ListNode* curr = head;
       ListNode* prev = nullptr;


       while (k--) {
           prev = curr;
           curr = curr->next;
       }

       prev->next = nullptr;
       ListNode* tmp = curr;
       while (tmp->next) {
           tmp = tmp->next;
       }
       tmp->next = head;
       head = curr;
       return head;
   }

   // problem 133 : You are given two strings s and t consisting of only lowercase English letters.
   // Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s. A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
   int appendCharacters(string s, string t) {
       if (s.find(t) != string::npos) {
           return 0;
       }
       int j = 0;
       for (int i = 0; i < s.length(); i++) {
           if (s[i] == t[j]) {
               j++;
           }
       }
       return (t.substr(j)).length();
   }

   // problem 134 : Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
   // palindrome that can be built with those letters. Letters are case sensitive, for example, "Aa" is not considered a palindrome.
   int longestPalindrome(string s) {
       vector<int>v(52, 0);
       for (int i = 0; i < s.length(); i++) {
           if (s[i] < 91) {
               v[s[i] - 65]++;
           }
           else
               v[s[i] - 97 + 26]++;
       }
       int maxOdd = 0;
       int ans = 0;
       bool hasOdd = false;
       for (int& i : v) {
           if (i % 2 == 0) {
               ans += i;
           }
           else {
               ans += i - 1;
               hasOdd = true;
           }

       }
       return (ans + (hasOdd ? 1 : 0));
   }

   // problem 135 : You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
   // numberOfBoxesi is the number of boxes of type i. numberOfUnitsPerBoxi is the number of units in each box of the type i. You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck.You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
   // Return the maximum total number of units that can be put on the truck.
   int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
       sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] > b[1];
           });
       int ans = 0;
       for (int i = 0; i < boxTypes.size(); i++) {
           truckSize -= boxTypes[i][0];
           if (truckSize < 0) {
               ans += ((boxTypes[i][0] + truckSize) * boxTypes[i][1]);
               break;
           }
           ans += boxTypes[i][0] * boxTypes[i][1];
       }
       return ans;
   }

   // problem 136 :  Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). You may return the answer in any order.
   vector<string> commonChars(vector<string>& words) {
       string smWord = words[0];
       vector<string>ans;
       for (int i = 1; i < words.size(); i++) {
           if (words[i].length() < smWord.length()) {
               smWord = words[i];
           }
       }
       for (int i = 0; i < smWord.length(); i++) {
           char c = smWord[i];
           bool test = true;
           for (string& s : words) {
               int pos = s.find(c);
               if (pos == string::npos) {
                   test = false;
                   break;
               }
               else
                   s[pos] = '*';
           }
           if (test) {
               string str = "";
               str += c;
               ans.push_back(str);
           }
       }
       return ans;
   }

   // problem 137 : Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
   // Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
   bool isNStraightHand(vector<int>hand, int groupSize) {
       if (hand.size() % groupSize != 0)
           return false;

       if (groupSize == 1)
           return true;

       int nb = hand.size() / groupSize;
       sort(hand.begin(), hand.end());
       int count = 1;
       int val = hand[0];
       while (true) {
           if (count == groupSize) {
               nb--;
               if (nb == 0) {
                   break;
               }
               count = 1;
               val = hand[1];
               hand.erase(hand.begin() + 1);
           }
           auto it = find(hand.begin(), hand.end(), val + 1);
           if (it != hand.end()) {
               val++;
               count++;
               hand.erase(it);
           }
           else
               return false;
       }
       return true;
   }
   
   // problem 138 : In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".
   // Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the sentence with the root forming it.If a derivative can be replaced by more than one root, replace it with the root that has the shortest length. Return the sentence after the replacement.
   string replaceWords(vector<string>& dictionary, string sentence) {
       unordered_set<string> st(dictionary.begin(), dictionary.end());

       string ans = "";
       int i = 0;
       while (i < sentence.length()) {
           string word = "";
           bool skip = false;
           while (i < sentence.length() && sentence[i] != ' ') {
               if (skip) {
                   i++;
                   continue;
               }
               word += sentence[i++];
               if (st.find(word) != st.end()) {
                   skip = true;
               }
           }
           ans += word;
           if (i < sentence.length() && sentence[i] == ' ') {
               ans += " ";
           }
           i++;
       }
       return ans;
   }

   // problem 139 : A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
   // You are given an integer array heights representing the current order that the students are standing in.Each heights[i] is the height of the ith student in line(0 - indexed).
   // Return the number of indices where heights[i] != expected[i].
   int heightChecker(vector<int>& heights) {
       vector<int> expected(heights.begin(), heights.end());
       int count = 0;
       sort(expected.begin(), expected.end());
       for (int i = 0; i < heights.size(); i++) {
           if (expected[i] != heights[i]) {
               count++;
           }
       }
       return count;
   }

   // problem 140 : Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
   // Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
   vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       vector<bool>used(arr1.size(), false);
       vector<int>ans;
       for (int i = 0; i < arr2.size(); i++) {
           for (int j = 0; j < arr1.size(); j++) {
               if (arr2[i] == arr1[j]) {
                   ans.push_back(arr2[i]);
                   used[j] = true;
               }
           }
       }
       multiset<int>st;
       for (int j = 0; j < used.size(); j++) {
           if (!used[j]) {
               st.insert(arr1[j]);
           }
       }
       for (auto it = st.begin(); it != st.end(); it++) {
           ans.push_back(*it);
       }
       return ans;
   }

   // problem 141 : Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
   bool threeConsecutiveOdds(vector<int>& arr) {
       int count = 0;
       for (int i : arr) {
           if (i % 2 != 0) {
               count++;
           }
           else
               count = 0;
           if (count == 3) {
               return true;
           }
       }
       return false;
   }

   // problem 142 : Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
   vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int, int>occ;
       vector<int>v;
       for (int i : nums1) {
           occ[i]++;
       }
       for (int i : nums2) {
           if (occ[i] > 0)
           {
               v.push_back(i);
               occ[i]--;
           }
       }
       return v;
   }

   // problem 143 : You are given an integer array nums. In one move, you can choose one element of nums and change it to any value.
   // Return the minimum difference between the largest and smallest value of nums after performing at most three moves.
   int minDifference(vector<int>& nums) {
       if (nums.size() < 5)
           return 0;
       sort(nums.begin(), nums.end());
       int ans = INT_MAX;
       for (int i = 0; i < 4; i++) {
           ans = min(nums[nums.size() - 1 - 3 + i] - nums[i], ans);
       }
       return ans;
   }


   // problem 144 : You are given two integers n and k.
   // Initially, you start with an array a of n integers where a[i] = 1 for all 0 <= i <= n - 1. After each second, you simultaneously update each element to be the sum of all its preceding elements plus the element itself.For example, after one second, a[0] remains the same, a[1] becomes a[0] + a[1], a[2] becomes a[0] + a[1] + a[2], and so on.
   // Return the value of a[n - 1] after k seconds. Since the answer may be very large, return it modulo 109 + 7.
   int valueAfterKSeconds(int n, int k) {
       vector< long long> v(n, 1);
       const  long long MOD = 1000000007;

       for (int i = 0; i < k; i++) {
           long long sum = 1;
           for (int j = 1; j < n; j++) {
               sum = (sum + v[j]) % MOD;
               v[j] = sum;
           }
       }
       return v[n - 1];
   }

   // problem 145 : You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.
   // For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.
   // Return the head of the modified linked list.
   ListNode* mergeNodes(ListNode* head) {
       int sum = 0;
       ListNode* ans = nullptr;
       ListNode* last = nullptr;
       ListNode* tmp = head->next;
       while (tmp) {
           if (tmp->val == 0) {
               ListNode* nvl = new ListNode(sum);
               if (ans == nullptr) {
                   ans = nvl;
               }
               else {
                   last->next = nvl;
               }
               last = nvl;
               sum = 0;
           }
           else {
               sum += tmp->val;
           }
           tmp = tmp->next;
       }
       return ans;

   }

};


