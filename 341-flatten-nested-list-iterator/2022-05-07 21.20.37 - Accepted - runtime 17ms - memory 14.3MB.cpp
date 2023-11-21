/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    int pos = 0;
    vector<int> ints;
    void flattenList(vector<NestedInteger> &nestedList){
        for(auto NI: nestedList){
            if(NI.isInteger()){
                ints.push_back(NI.getInteger());
            }else{
                flattenList(NI.getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattenList(nestedList);
    }
    
    int next() {
        if(!hasNext()) throw new exception();
        return ints[pos++];
    }
    
    bool hasNext() {
        return pos < ints.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */