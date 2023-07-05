#include<bits/stdc++.h>
#include"rdb.h"

vector<Relation *> LIST;
int main()
{
    int n = 1;
    while (n)
    {
        cout << endl ;
        cout << "Enter 1 : to Create a new empty table\n";
        cout << "Enter 2 : to Delete an existing table\n";
        cout << "Enter 3 : to add a record  to a table\n";
        cout << "Enter 4 : to print a table in the appropriate format\n";
        cout << "Enter 5 : to Create a new table using Union\n";
        cout << "Enter 6 : to Create a new table using Difference \n";
        cout << "Enter 7 : to Create a new table using Cartesian Product\n";
        cout << "Enter 8 : to Create a new table using Projection\n";
        // cout << "Enter 9 : to Create a new table using Selection\n";
        cout << "Enter 9 : to Rename an existing table using Rename\n";
        cout << "Enter 10 : to Create a new table using Natural Join\n";
        cout << "Enter 11 : to print the current number of existing tables\n";
        cout << "Enter 0 : to exit\n";
        cout << "\nEnter the value:\n";
        cin >> n;
        if (n == 0)
        {
            continue;
        }
        else if (n == 1)
        {
            // Relation* T = new Relation;

            Relation *T = new Relation;

            int num_attr;
            cout << "Enter the number of attributes of the table:";
            cin >> num_attr;
            T->set_natttr(num_attr);
            vector<string> temp, given;
            vector<int> ind;
            for (int i = 0; i < num_attr; i++)
            {
                string x;
                cout << "Enter the attrnames[" << i << "]:";
                cin >> x;
                // cout << "x = " << x << "\n";
                // temp.push_back(x);
                // given.push_back(x);
                T->set_attrnames(x);
                
                // cout << "x = " << x << "\n";
                // cout << "x = " << x << "\n";
            }
            T->set_attrinds();
            LIST.push_back(T);
        }
        else if (n == 3)
        {

            if (LIST.size() == 0)
            {
                cout << "No existing tables.Create a new table\n";
            }

            else
            {
                cout << "Number of existing tables =" << LIST.size() << "\n";
                int ind;
                cout << "Enter the index of the table for which record needed to be added:(zero indexing):";
                cin >> ind;
                Record *record = new Record;
                int k;
                cout << LIST[ind]->get_natttr();
                for (int i = 0; i < LIST[ind]->get_natttr(); i++)
                {
                   // LIST[ind]->print_attributes();
                    cout << "Enter the type of attribute:(\n1 for int\n2 for float\n3 for string\n)";
                    cin >> k;
                    if (k == 1)
                    {
                        int i;
                        cout << "Enter an integer value:";
                        cin >> i;
                        derived_integer *temp = new derived_integer(i);
                        // temp->integer(i);
                        record->addattr((Attr *)temp);
                        // LIST[ind]->add_to_list(record);
                    }
                    else if (k == 2)
                    {
                        float f;
                        cout << "Enter a float value:";
                        cin >> f;
                        derived_float *temp = new derived_float(f);
                        // temp->get_float(f);

                        record->addattr((Attr *)temp);
                        // LIST[ind]->add_to_list(record);
                    }
                    else if (k == 3)
                    {
                        string s;
                        cout << "Enter a string:";
                        cin >> s;
                        derived_string *temp = new derived_string(s);
                        record->addattr((Attr *)temp);
                        // LIST[ind]->add_to_list(record);
                    }
                    
                }
                vector <int> inds;
                for(int order=0;order<LIST[ind]->get_natttr();order++) inds.push_back(LIST[ind]->get_attrinds(order));
                LIST[ind]->add_to_list(record,inds);
                // record->print_vector() ;
                
                cout << "RECORD ADDED\n";
            }
        }
        else if (n == 2)
        {
            int j;
            if (LIST.size() == 0)
            {
                cout << "No existing tables\n";
            }
            else{
            cout << "Enter the index of the table needed to be removed:";
            cin >> j;
            LIST.erase(LIST.begin() + j);
            }
        }
        else if (n == 4)
        {
            int j;
            if (LIST.size() == 0)
            {
                cout << "No existing tables\n";
            }
            else{
            cout << "Enter the index of the table needed to be printed:";
            cin >> j;
            Relation *temp = LIST[j];
            temp->print_attributes();
            temp->print_list();
            }
        }
        else if (n == 5)
        {
            cout << "Enter the indices of existing tables needed to be united:";
            int a,b;
            cin >> a >> b;
            Relation* R = new Relation;
            R = Union(LIST[a],LIST[b]);
            if(R!=NULL){
            R->print_attributes();
            R->print_list();
            LIST.push_back(R);
            }
        }
        else if (n == 6)
        {
            cout << "Enter the indices of existing tables needed to be differentiated:";
            int a,b;
            cin >> a >> b;
            Relation* R = new Relation;
            
            R = difference(LIST[a],LIST[b]);
            if(R!=NULL){
            R->print_attributes();
            R->print_list();
            LIST.push_back(R);
            }
        }
        else if (n == 7)
        {
            cout << "Enter the indices of existing tables needed to be multiplied by cartesian product:";
            int a,b;
            cin >> a >> b;
            // if(R!=NULL){
            Relation* R = new Relation;
            // if(R!=NULL){
            R = catersianproduct(LIST[a],LIST[b]);
            if(R!=NULL){
            R->print_attributes();
            R->print_list();
            LIST.push_back(R);
            }
        }
        else if (n == 8)
        {
            cout << "Enter the index of existing table needed to be projected:";
            int a;
            cin >> a;
            int b;
            cout << "Enter the no. of attributes to be in the projected table:";
            cin >> b;
            list<string> l;
            for (int i = 0; i < b; i++)
            {
                cout << "Enter l[" << i << "]:";
                string s;
                cin >> s;
                l.push_back(s);
            }
            // if(R!=NULL){
            Relation* R = new Relation;
            // if(R!=NULL){
            R = projection(LIST[a],l);
            if(R!=NULL){
            R->print_attributes();
            R->print_list();
            LIST.push_back(R);
            }
        }
        else if(n == 9)
        {
            cout << "Enter the index of the existing table to be renamed:";
            int a;
            cin >> a;
            cout << "Enter the 2 attribute names to be renamed:";
            string x,y;
            cin >> x >> y;
            // if(R!=NULL){
            Relation* R = new Relation;
            // if(R!=NULL){
            R = difference(LIST[a],x,y);
            if(R!=NULL){
            R->print_attributes();
            R->print_list();
            LIST.push_back(R);
            }
        }
        else if (n == 10)
        {
            cout << "Enter the indices of existing tables needed to be naturally joined:";
            int a,b;
            cin >> a >> b;
            cout << "Enter no of attributes to be joined\n" ;
            int k ;
            cin >> k ;
            list<string> l;
            for (int i = 0; i < k; i++)
            {
                cout << "Enter l[" << i << "]:";
                string s;
                cin >> s;
                l.push_back(s);
            }
            
            Relation* R = new Relation;
            // if(R!=NULL){
            R = naturaljoin(LIST[a],LIST[b],l);
            if(R!=NULL){
            R->print_attributes();
            R->print_list();
            LIST.push_back(R);
            }
        }
        else if(n == 11)
        {
            cout << "Current number of existing tables : " << LIST.size()<<"\n";
        }
        
        
    }
    cout << "Program Exitted\n";
}
