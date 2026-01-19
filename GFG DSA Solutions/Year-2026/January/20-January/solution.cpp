class Solution {
    vector<char> ops;
    string doc;
  public:
    void append(char x) {
        // append x into document
        ops.clear();
        doc += x;
    }

    void undo() {
        // undo last change
        if(doc.size()==0)
            return ;
        ops.push_back(doc[doc.size()-1]);
        doc.pop_back();
    }

    void redo() {
        // redo changes
        if(ops.size())
            doc += ops[ops.size()-1], ops.pop_back();
    }

    string read() {
        // read the document
        return doc;
    }
};
