#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
//Definition for singly - linked list.
 struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

 //Treenode
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
     
 };

//Maximum Nesting Depth of the Parentheses    
class stack1 {
    int maxDepth(string s) {
        int ans = 0, p = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            int c = s[i];
            switch (c) {
            case '(':
                p++;
                ans = (ans < p) ? p : ans;
                break;
            case ')': p--; break;
            }
        }
        return ans;
    }
};

//Baseball game
class stack2 {
    int calPoints(vector<string>& operations) {
        vector<int> v;
        for (int i = 0; i < operations.size(); i++) {
            int n = v.size();
            if (operations[i] == "+") v.push_back(v[n - 1] + v[n - 2]);
            else if (operations[i] == "C") v.pop_back();
            else if (operations[i] == "D") v.push_back(2 * v[n - 1]);
            else v.push_back(stoi(operations[i]));
        }
        int sum = 0;
        for (auto s : v) sum += s;
        return sum;
    }
};

//Number of Students Unable to Eat Lunch
class queue3 {
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> student, sandwich;
        int Loop = 0;

        for (int i = 0; i < students.size(); i++)
            student.push(students[i]);
        for (int i = 0; i < sandwiches.size(); i++)
            sandwich.push(sandwiches[i]);

        while (true)
        {
            if (Loop == student.size()) break;

            if (student.front() != sandwich.front())
            {
                student.push(student.front());
                student.pop();
                Loop++;
            }
            else
            {
                Loop = 0;
                student.pop();
                sandwich.pop();
            }
        }
        return student.size();
    }
};

//implement stack using queue
class stack4 {
public:
    stack4() {

    }

    queue<int> q;

    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

//Time Required to Buy Tickets
class queue5 {
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int total = tickets[k];

        for (int i = 0; i < k; i++) {
            total += min(tickets[k], tickets[i]);
        }
        for (int i = k + 1; i < n; i++) {
            total += min(tickets[k] - 1, tickets[i]);
        }
        return total;
    }
};

//Convert Binary Number in a Linked List to Integer
class LinkedLists1 {
public:
    int getDecimalValue(ListNode* head) {
        int nums = 0;
        while (head != nullptr) {
            nums = nums * 2 + head->val;
            head = head->next;
        }
        return nums;
    }
};
//Merge Two Sorted Lists
class LinkedLists2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
//	Remove Linked List Elements
class LinkedLists3 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        head->next = removeElements(head->next, val);
        if (head->val == val) {
            return head->next;
        }
        return head;
    }
};
//Reverse Linked List
class LinkedLists4 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;

        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = node;
            node = head;
            head = temp;
        }

        return node;
    }
};
//Linked List Cycle
class LinkedLists5 {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
//Range Sum of BST
class BinarySearchTree1 {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        while (root) {
            if (root->left) {
                TreeNode* temp = root->left;
                TreeNode* curr = root->left;
                while (temp->right) {
                    temp = temp->right;
                }
                temp->right = root;
                root->left = NULL;
                root = curr;
            }
            else {
                if (root->val >= low && root->val <= high) {
                    sum += root->val;
                }
                root = root->right;
            }
        }
        return sum;
    }
};
// Search in a Binary Search Tree
class BinarySearchTree2 {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root) {
            if (root->val == val) {
                return root;
            }
            else if (root->val > val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return nullptr;
    }
};
//validate binary search tree
class BinarySearchTree3 {
public:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);


        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] <= v[i - 1])
            {
                return false;
                break;
            }
        }

        return true;

    }
};
//Insert into a Binary Search Tree
class BinarySearchTree4 {
private:
    TreeNode* solve(TreeNode* node, int val)
    {
        if (node == NULL)
        {
            node = new TreeNode(val);
            return node;
        }

        if (val < node->val)
        {
            node->left = solve(node->left, val);
        }
        else if (val > node->val)
        {
            node->right = solve(node->right, val);
        }

        return node;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        return solve(root, val);
    }
};
//Validate Binary Search Tree
class BinarySearchTree5 {
public:
    void inorder(TreeNode* root, vector<int>& v)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);

    }
    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);


        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] <= v[i - 1])
            {
                return false;
                break;
            }
        }

        return true;

    }
};
//check if the nr is fascinating
class HashTable1 {
public:
    bool isFascinating(int n) {
        string str = to_string(n) + to_string(2 * n) + to_string(3 * n);
        int h[10] = { 0 };
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
                return false;
            h[str[i] - '0']++;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (h[i] != 1)
                return false;
        }
        return true;
    }
};
//minimum common value
class HashTable2 {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m.find(nums2[i]) != m.end()) {
                return nums2[i];
            }
        }
        return -1;
    }
};
//Sort the People
class HashTable3 {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> answer;
        int n = names.size();
        map <int, string> mp;
        for (int i = 0; i < n; i++)
            mp[heights[i]] = names[i];
        map <int, string> ::reverse_iterator itr;
        for (itr = mp.rbegin(); itr != mp.rend(); itr++)
            answer.push_back(itr->second);
        return answer;
    }
};
//Integer to Roman
class HashTable4 {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = { {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                         {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"},
                                         {5, "V"}, {4, "IV"}, {1, "I"} };

        string res = "";

        for (auto it : roman)
        {
            while (num >= it.first)
            {
                res += it.second;
                num -= it.first;
            }
        }
        return res;
    }
};
//Roman to Integer
class HashTable5 {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] < m[s[i + 1]]) {
                ans -= m[s[i]];
            }
            else {
                ans += m[s[i]];
            }
        }
        return ans;
    }
};