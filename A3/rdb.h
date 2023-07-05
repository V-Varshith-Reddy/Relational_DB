#include <bits/stdc++.h>
using namespace std;

class derived_integer;
class derived_float;
class derived_string;

class Attr
{
protected:
    int type; // 1(int) 2(float) 3(string)

public:
    Attr()
    {
        type = 0;
    }
    /*void set_type(int x) const {
        this->type = x ;
    }*/
    int get_type() const
    {
        return this->type;
    }

    /*virtual Attr * copy(){
        // Attr * temp = new Attr ;
        // temp->type = this->type ;
        if(this->type==1){
            derived_integer * newtemp = new derived_integer() ;
            newtemp = (derived_integer *) temp ;
            newtemp->integer = (derived_integer *)this->integer ;
        }
        if(this->type==2){
            derived_float * newtemp /*= new derived_float ;
            newtemp*/
    /*= (derived_float *) temp ;
newtemp->floating_point = (derived_float *)this->floating_point ;
}
if(this->type==3){
derived_string * newtemp /*= new derived_string ;
newtemp*/
    /*/= (derived_string *) temp ;
newtemp->string = (derived_string *)this->string ;
}
return temp ;
}*/

    virtual Attr *copy() = 0;
    virtual void print() = 0;
    virtual bool operator==(const Attr &right) = 0;
    virtual bool operator!=(const Attr &right) = 0;
    virtual bool operator<(const Attr &right) = 0;
    virtual bool operator>(const Attr &right) = 0;
    virtual bool operator<=(const Attr &right) = 0;
    virtual bool operator>=(const Attr &right) = 0;
};

class derived_integer : public Attr
{

    int /*type ,*/ integer;

public:
    Attr *copy()
    {
        derived_integer *temp = new derived_integer(this->integer);
        // temp->integer = this->integer ;
        Attr *newtemp = (Attr *)temp;
        // newtemp->type = 1 ;
        return newtemp;
    }
    void print()
    {
        cout << integer << " ";
    }
    derived_integer(int integer_) : integer(integer_)
    {
        this->type = 1;
    }

    /*int get_type() const {
        return type ;
    }*/
    int get_int() const
    {
        return integer;
    }

    bool operator==(const Attr &right)
    {
        derived_integer *temp = (derived_integer *)&right;
        int type1 = 1, type2 = temp->get_type();
        if (type1 != type2)
            return false;
        if (this->integer == temp->integer)
            return true;
        return false;
    }
    bool operator!=(const Attr &right)
    {
        return !operator==(right);
    }
    bool operator<(const Attr &right)
    {
        derived_integer *temp = (derived_integer *)&right;
        int type1 = 1, type2 = temp->get_type();
        if (type1 != type2)
            return false;
        if (this->integer < temp->integer)
            return true;
        return false;
    }
    bool operator>(const Attr &right)
    {
        derived_integer *temp = (derived_integer *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return !(operator==(right) || operator<(right));
    }
    bool operator<=(const Attr &right)
    {
        derived_integer *temp = (derived_integer *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return (operator==(right) || operator<(right));
    }
    bool operator>=(const Attr &right)
    {
        derived_integer *temp = (derived_integer *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return (operator==(right) || operator>(right));
    }
};

class derived_float : public Attr
{

    // int type  ;
    float floating_point;

public:
    Attr *copy()
    {
        derived_float *temp = new derived_float(this->floating_point);
        // temp->floating_point = this->floating_point ;
        Attr *newtemp = (Attr *)temp;
        // newtemp->type = 2 ;
        return newtemp;
    }

    derived_float(float floating_point_) : /*type(2) ,*/ floating_point(floating_point_)
    {
        this->type = 2;
    }
    void print()
    {
        cout << floating_point << " ";
    }
    /*int get_type() const {
        return type ;
    }*/
    float get_float() const
    {
        return floating_point;
    }

    bool operator==(const Attr &right)
    {
        derived_float *temp = (derived_float *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        if (this->floating_point == temp->floating_point)
            return true;
        return false;
    }
    bool operator!=(const Attr &right)
    {
        return !operator==(right);
    }
    bool operator<(const Attr &right)
    {
        derived_float *temp = (derived_float *)&right;
        int type1 = 2, type2 = temp->get_type();
        if (type1 != type2)
            return false;
        if (this->floating_point < temp->floating_point)
            return true;
        return false;
    }
    bool operator>(const Attr &right)
    {
        derived_float *temp = (derived_float *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return !(operator==(right) || operator<(right));
    }
    bool operator<=(const Attr &right)
    {
        derived_float *temp = (derived_float *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return (operator==(right) || operator<(right));
    }
    bool operator>=(const Attr &right)
    {
        derived_float *temp = (derived_float *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return (operator==(right) || operator>(right));
    }
};

class derived_string : public Attr
{

    // int type ;
    string str;

public:
    Attr *copy()
    {
        derived_string *temp = new derived_string(this->str);
        // temp->str = this->str ;
        Attr *newtemp = (Attr *)temp;
        // newtemp->type = 3 ;
        return newtemp;
    }

    derived_string(string str_) : /*type(3) ,*/ str(str_)
    {
        this->type = 3;
    }
    void print()
    {
        cout << str << " ";
    }

    /*int get_type() const {
        return type ;
    }*/
    string get_string() const
    {
        return str;
    }

    bool operator==(const Attr &right)
    {
        derived_string *temp = (derived_string *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        if (this->str == temp->get_string())
            return true;
        return false;
    }
    bool operator!=(const Attr &right)
    {
        return !operator==(right);
    }
    bool operator<(const Attr &right)
    {
        derived_string *temp = (derived_string *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        if (this->str < temp->str)
            return true;
        return false;
    }
    bool operator>(const Attr &right)
    {
        derived_string *temp = (derived_string *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return !(operator==(right) || operator<(right));
    }
    bool operator<=(const Attr &right)
    {
        derived_string *temp = (derived_string *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return (operator==(right) || operator<(right));
    }
    bool operator>=(const Attr &right)
    {
        derived_string *temp = (derived_string *)&right;
        int type1 = this->get_type(), type2 = temp->get_type();
        if (type1 != type2)
            return false;
        return (operator==(right) || operator>(right));
    }
};

class Relation;

class Record
{
    vector<Attr *> attrptr;

public:
    friend class Relation;

    void addattr(Attr *temp)
    {
        attrptr.push_back(temp->copy());
    }

    Attr *get_attr(int i)
    {
        return attrptr[i];
    }
    int get_size()
    {
        return this->attrptr.size();
    }
    Record() {}
    void setdata(Attr *attrptr_)
    {
        attrptr.push_back(attrptr_);
        // sort(attrptr.begin(),attrptr.end()) ;
    }
    void print_vector(/*vector <Attr * > attrptr*/)
    {
        vector<Attr *> attrptr = this->attrptr;
        for (int i = 0; i < attrptr.size(); i++)
        {
            int type = attrptr[i]->get_type();
            if (type == 1)
            {
                derived_integer *temp = (derived_integer *)attrptr[i];
                cout << temp->get_int() << " ";
            }
            else if (type == 2)
            {
                derived_float *temp = (derived_float *)attrptr[i];
                cout << temp->get_float() << " ";
            }
            else
            {
                derived_string *temp = (derived_string *)attrptr[i];
                cout << temp->get_string() << " ";
            }
        }
        cout << endl;
        return;
    }
    bool operator==(/*const Record &*/ Record right)
    {
        vector<Attr *> v1 = this->attrptr;
        vector<Attr *> v2 = right.attrptr;
        int n1 = v1.size(), n2 = v2.size();
        if (n1 != n2)
            return false;
        for (int i = 0; i < n1; i++)
        {
            if (*v1[i] != *v2[i])
                return false;
        }
        return true;
    }
    Record *copy()
    {
        Record *temp = new Record;
        // vector <Attr * > test = r->attrptr ;
        for (int i = 0; i < this->get_size(); i++)
        {
            temp->attrptr.push_back(this->attrptr[i]->copy());
        }
        return temp;
    }
};

class Relation
{
    int natttr, nrecs;        // number of attributes and records
    vector<string> attrnames; // schema
    vector<int> attrinds;     // mapping schema to indices
    list<Record *> recs;      // list of records
public:
    Relation(int natttr_ = 0, int nrecs_ = 0) : natttr(natttr_), nrecs(nrecs_) {}

    int get_attrinds(int i)
    {
        return attrinds[i];
    }
    void set_natttr(int n)
    {
        natttr = n;
        return;
    }

    void rename(string s1, string s2)
    {
        for (int i = 0; i < attrnames.size(); i++)
        {
            if (attrnames[i] == s1)
            {
                attrnames[i] = s2;
                return;
            }
        }
        cout << "No string found to rename\n";
        return;
    }
    void set_attrnames(string str)
    {
        attrnames.push_back(str);
        return;
    }
    void increment()
    {
        (this->natttr)++;
    }
    int get_natttr()
    {
        return natttr;
    }
    int get_nrecs()
    {
        return nrecs;
    }
    string get_attrnames(int i)
    {
        return attrnames[i];
    }
    auto get_recs()
    {
        return recs;
    }
    /*vector get_vector(){
        return attrnames ;
    }*/
    void set_attrinds(/*vector <string> v = get_vector()*/)
    {
        vector<string> v = attrnames;
        vector<string> v2 = attrnames;
        // for(int i=0;i<v.size();i++) v2.push_back(v[i]) ;
        sort(v.begin(), v.end());
        int j;
        for (int i = 0; i < v.size(); i++)
        {
            for (j = 0; j < v.size(); j++)
            {
                if (v2[j] == v[i])
                    break;
            }
            attrinds.push_back(j);
        }
    }
    void print_attrinds()
    {
        for (int i = 0; i < attrinds.size(); i++)
            cout << i << " -> " << attrinds[i] << endl;
        return;
    }
    void set_list(Record *record)
    {
        vector<Attr *> v; //= record -> attrptr ;
        for (int i = 0; i < record->attrptr.size(); i++)
        {
            int index = attrinds[i];
            v.push_back(record->attrptr[index]);
        }
        Record *temp;
        temp = new Record;
        // temp -> attrptr = v ;
        for (int i = 0; i < v.size(); i++)
            temp->attrptr.push_back(v[i]);
        recs.push_back(temp);
    }
    void add_to_list(Record *record)
    {
        recs.push_back(record);
        nrecs++;
    }

    void add_to_list(Record *record,vector <int> inds)
    {
        Record* newrecord = new Record();
        for(int i=0;i<inds.size();i++)
        {
            newrecord->addattr((record->get_attr(inds[i]))->copy());
        }
        add_to_list(newrecord);
    }
    void print_attributes(){
        vector<string> v;
        for (int i = 0; i < this->get_natttr(); i++)
        {
            v.push_back(attrnames[i]);
        }
        sort(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    void print_list()
    {
        for (auto it = recs.begin(); it != recs.end(); it++)
        {
            // it->print_vector() ;
            Record *temp = (*it);
            temp->print_vector();
        }
    }
    auto get_begin()
    {
        return this->recs.begin();
    }
    auto get_end()
    {
        return this->recs.end();
    }
    void self_map_attrindes(int n)
    {
        for (int i = 0; i < n; i++)
            this->attrinds.push_back(i);
    }
};
Relation *Union(Relation *R1, Relation *R2);
Relation *difference(Relation *R1, Relation *R2);
Relation *catersianproduct(Relation *R1, Relation *R2);
Relation *difference(Relation *R1, string s1, string s2);
Relation *projection(Relation *R1, list<string> projectattrs);
bool can_be_joined(Record *a, Record *b, vector<int> v1, vector<int> v2);
bool can_be_joined(vector<Attr *> a, vector<Attr *> b, vector<int> v1, vector<int> v2);
Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr);