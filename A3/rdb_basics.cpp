#include<bits/stdc++.h>
#include"rdb.h"

Relation *Union(Relation *R1, Relation *R2)
{
    // vector < string > v ;
    vector<string> v1, v2;
    for (int i = 0; i < R1->get_natttr(); i++)
        v1.push_back(R1->get_attrnames(i));
    for (int i = 0; i < R2->get_natttr(); i++)
        v2.push_back(R2->get_attrnames(i));
    // vector < string > v1 = (R1->get_attrnames()) , v2 = (R2->get_attrnames()) ;
    if (v1.size() != v2.size())
    {
        cout << "1)Not union compatable\n";
        return NULL;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        int k = 0;
        for (int j = 0; j < v1.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                k = 1;
                break;
            }
        }
        if (k == 0)
        {
            cout << "2)Not union compatable\n";
            return NULL;
        }
    }
    // cout << "384\n";
    list<Record *> l1, l2;

    // l1 = R1->get_recs() , l2 = R2->get_recs() ;
    Relation *R3 = new Relation /*(R1->get_natttr() + R2->get_natttr())*/;
    R3->self_map_attrindes(R1->get_natttr());
    vector<string> v3;
    for (int i = 0; i < v1.size(); i++)
    {
        v3.push_back(v1[i]);
        R3->increment();
    }
    sort(v3.begin(), v3.end());
    // cout << "391\n";
    for (int i = 0; i < v3.size(); i++)
        R3->set_attrnames(v3[i]);
    for (auto it = R1->get_begin(); it != R1->get_end(); it++)
    {
        Record *temp = (*it)->copy();
        // temp = new Record ;
        // temp->copy(*it,R1->get_natttr()) /*->get_recs()*/ ;
        R3->add_to_list(temp);
        // cout << "*****\n";
        // temp->print_vector();
        // cout << endl;
    }
    // cout << "399\n";
    list<Record *> l3;
    // l3 = R2->get_recs() ;
    for (auto it = R2->get_begin(); it != R2->get_end(); it++)
    {
        Record *temp = (*it)->copy();
        // temp = new Record ;
        // temp->copy(*it,R2->get_natttr())/*.get_recs()*/ ;
        int x = 0;
        list<Record *> l4;
        // l4 = R1->get_recs() ;
        auto it2 = R1->get_begin();
        // cout << "*****\n";
        // temp->print_vector();
        // cout << endl;
        for (; it2 != R1->get_end(); it2++)
        {
            // cout << "*****\n" ; temp->print_vector(); cout << endl ;
            // cout << "**\n" ; (*it2)->print_vector() ; cout << endl ;
            if (*temp == (**it2))
            {
                // cout << "412\n";
                x = 1;
                break;
            }
        }
        if (x == 0)
        {
            // cout << "418\n";
            Record *t2 = (*it)->copy();
            // t2 = *it2 ;
            R3->add_to_list(t2);
        }
    }
    // R3->print_list() ;
    cout << "***Union ended\n";

    return R3;
}

Relation *difference(Relation *R1, Relation *R2)
{
    vector<string> v1, v2;
    for (int i = 0; i < R1->get_natttr(); i++)
        v1.push_back(R1->get_attrnames(i));
    for (int i = 0; i < R2->get_natttr(); i++)
        v2.push_back(R2->get_attrnames(i));
    // vector < string > v1 = (R1->get_attrnames()) , v2 = (R2->get_attrnames()) ;
    if (v1.size() != v2.size())
    {
        cout << "1)Not difference compatable\n";
        return NULL;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        int k = 0;
        for (int j = 0; j < v1.size(); j++)
        {
            if (v1[i] == v2[j])
            {
                k = 1;
                break;
            }
        }
        if (k == 0)
        {
            cout << "2)Not difference compatable\n";
            return NULL;
        }
    }

    list<Record *> l1, l2;
    // l1 = R1->get_recs() , l2 = R2->get_recs() ;
    Relation *R3 = new Relation /*(R1->get_natttr() + R2->get_natttr())*/;
    R3->self_map_attrindes(R1->get_natttr());
    vector<string> v3;
    // for(int i=0;i<v1.size();i++) v3.push_back(v1[i]) ;
    for (int i = 0; i < v1.size(); i++)
    {
        v3.push_back(v1[i]);
        R3->increment();
    }
    sort(v3.begin(), v3.end());
    for (int i = 0; i < v3.size(); i++)
        R3->set_attrnames(v3[i]);
    for (auto it = R1->get_begin(); it != R1->get_end(); it++)
    {
        int z = 0;
        for (auto it2 = R2->get_begin(); it2 != R2->get_end(); it2++)
        {
            if (**it == **it2)
            {
                z = 1;
                break;
            }
        }
        if (z == 1)
            continue;
        Record *temp = (*it)->copy();
        // temp = new Record ;
        // temp->copy(*it,R1->get_natttr()) /*->get_recs()*/ ;
        R3->add_to_list(temp);
    }
    cout << "***Difference ended\n";
    return R3;
}

Relation *catersianproduct(Relation *R1, Relation *R2)
{
    vector<string> vleft, vright;
    for (int i = 0; i < R1->get_natttr(); i++)
        vleft.push_back(R1->get_attrnames(i));
    for (int i = 0; i < R2->get_natttr(); i++)
        vright.push_back(R2->get_attrnames(i));
    sort(vleft.begin(), vleft.end());
    sort(vright.begin(), vright.end());
    Relation *R3 = new Relation;
    vector<string> v;
    for (int i = 0; i < R1->get_natttr(); i++)
    {
        v.push_back(R1->get_attrnames(i));
        R3->increment();
    }
    for (int i = 0; i < R2->get_natttr(); i++)
    {
        v.push_back(R2->get_attrnames(i));
        R3->increment();
    }
    sort(v.begin(), v.end());
    R3->self_map_attrindes(R1->get_natttr() + R2->get_natttr());
    auto it1 = R1->get_begin();
    for (; it1 != R1->get_end(); it1++)
    {
        auto it2 = R2->get_begin();
        for (; it2 != R2->get_end(); it2++)
        {
            /*vector < Attr * > v2 ;
            vector < Attr * > v3 = (*it1)->attrptr ;
            vector < Attr * > v4 = (*it2)->attrptr ;
            for(int i=0;i<v3.size();i++) v.push_back(v3[i]) ;
            for(int i=0;i<v4.size();i++) v.push_back(v4[i]) ;*/
            int i = 0, j = 0, n = R1->get_natttr(), m = R2->get_natttr();
            vector<Attr *> temp;
            while (i < n && j < m)
            {
                if (vleft[i] <= vright[j])
                {
                    R3->set_attrnames(vleft[i]);
                    temp.push_back((*it1)->get_attr(i));
                    i++;
                }
                else
                {
                    R3->set_attrnames(vright[j]);
                    temp.push_back((*it2)->get_attr(j));
                    j++;
                }
            }
            if (j == m)
            {
                while (i < n)
                {
                    R3->set_attrnames(vleft[i]);
                    temp.push_back((*it1)->get_attr(i));
                    i++;
                }
            }
            else if (i == n)
            {
                while (j < m)
                {
                    R3->set_attrnames(vright[j]);
                    temp.push_back((*it2)->get_attr(j));
                    j++;
                }
            }
            Record *r = new Record;
            for (int i = 0; i < temp.size(); i++)
            {
                r->addattr(temp[i]);
            }
            // r->attrptr = temp ;
            // Record * r = temp.copy() ;
            R3->add_to_list(r);
        }
    }
    cout << "***Cartesian product ended\n";
    return R3;
}

Relation *difference(Relation *R1, string s1, string s2)
{
    R1->rename(s1, s2);
    cout << "***Rename ended\n";
    return R1;
}

Relation *projection(Relation *R1, list<string> projectattrs)
{
    Relation *R2 = new Relation;
    vector<string> v;
    for (int i = 0; i < R1->get_natttr(); i++)
        v.push_back(R1->get_attrnames(i));
    sort(v.begin(), v.end());
    vector<int> index;
    for (int i = 0; i < v.size(); i++)
    {
        for (auto it = projectattrs.begin(); it != projectattrs.end(); it++)
        {
            if ((*it) == v[i])
            {
                R2->set_attrnames(v[i]);
                index.push_back(i);
                break;
            }
        }
    }
    for (auto it = R1->get_begin(); it != R1->get_end(); it++)
    {
        int j = 0;
        vector<Attr *> temp;
        for (int i = 0; i < v.size(); i++)
        {
            if (i != index[j])
                continue;
            temp.push_back((*it)->get_attr(i));
            j++;
        }
        Record *r = new Record;
        for (int i = 0; i < temp.size(); i++)
        {
            r->addattr(temp[i]);
        }
        R2->add_to_list(r);
    }
    cout << "***Projection ended\n";
    return R2;
}

bool can_be_joined(Record *a, Record *b, vector<int> v1, vector<int> v2)
{
    // vector < Attr * > a = (*it1)->get_attr , b = (*it2)->attrptr ;
    // for(;it1!=)
    // cout<<"Can be joined new\n";
    // if(v1.size()!=v2.size()) return false ;
    // cout << "a = ";a->print_vector();
    // cout << "b = ";b->print_vector();
    // for(int i=0;i<v1.size();i++){
    //     cout << "itertion "<<i<<endl;
    //     if(*(a->get_attr(v1[i]))!=*(b->get_attr(v2[i])))
    //     {
    //         a->get_attr(v1[i])->print(); b->get_attr(v2[i])->print();cout<<endl;
    //         return false ;
    //     }
    // }
    // cout << "True\n";
    return true;
}
