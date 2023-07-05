#include<bits/stdc++.h>
#include"rdb.h"

bool can_be_joined(vector<Attr *> a, vector<Attr *> b, vector<int> v1, vector<int> v2)
{
    // vector < Attr * > a = (*it1)->get_attr , b = (*it2)->attrptr ;
    // for(;it1!=)
    // cout<<"Can be joined\n";
    if (v1.size() != v2.size())
        return false;
    for (int i = 0; i < v1.size(); i++)
    {
        // cout << "itertion "<<i<<endl;

        if (*a[v1[i]] != *b[v2[i]])
            return false;
    }
    // cout << "True\n";
    return true;
}

Relation *naturaljoin(Relation *R1, Relation *R2, list<string> joinattr)
{
    vector<string> vleft;
    for (int i = 0; i < R1->get_natttr(); i++)
        vleft.push_back(R1->get_attrnames(i));
    sort(vleft.begin(), vleft.end());
    vector<string> vright;
    for (int i = 0; i < R2->get_natttr(); i++)
        vright.push_back(R2->get_attrnames(i));
    sort(vright.begin(), vright.end());

    vector<int> v1, v2;
    for (int i = 0; i < vleft.size(); i++)
    {
        for (auto it = joinattr.begin(); it != joinattr.end(); it++)
        {
            if (vleft[i] == (*it))
                v1.push_back(i);
        }
    }
    for (int i = 0; i < vright.size(); i++)
    {
        for (auto it = joinattr.begin(); it != joinattr.end(); it++)
        {
            if (vright[i] == (*it))
                v2.push_back(i);
        }
    }
    // for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";cout<<endl;
    // for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";cout<<endl;
    Relation *R3 = new Relation;
    R3->self_map_attrindes(R1->get_natttr() + R2->get_natttr());
    for (auto it1 = R1->get_begin(); it1 != R1->get_end(); it1++)
    {
        for (auto it2 = R2->get_begin(); it2 != R2->get_end(); it2++)
        {
            vector<Attr *> a, b;
            for (int i = 0; i < R1->get_natttr(); i++)
                a.push_back((*it1)->get_attr(i));
            for (int i = 0; i < R2->get_natttr(); i++)
                b.push_back((*it2)->get_attr(i));
            // if(can_be_joined(*it1,*it2,v1,v2));
            if (can_be_joined(a, b, v1, v2))
            {
                int i = 0, j = 0, n = R1->get_natttr(), m = R2->get_natttr();
                vector<Attr *> temp;
                int c = 0;
                while (i < n && j < m)
                {

                    if (vleft[i] == vright[j])
                    {
                        R3->set_attrnames(vleft[i]);
                        temp.push_back((*it1)->get_attr(i)->copy());
                        i++;
                        j++;
                        c++;
                    }

                    else if (vleft[i] < vright[j])
                    {
                        R3->set_attrnames(vleft[i]);
                        temp.push_back((*it1)->get_attr(i)->copy());
                        i++;
                    }

                    else /* if(vleft[i]>vright[j])*/
                    {
                        R3->set_attrnames(vright[j]);
                        temp.push_back((*it2)->get_attr(j)->copy());
                        j++;
                    }
                }
                if (j == m)
                {
                    while (i < n)
                    {
                        R3->set_attrnames(vleft[i]);
                        temp.push_back((*it1)->get_attr(i)->copy());
                        i++;
                    }
                }
                else if (i == n)
                {
                    while (j < m)
                    {
                        R3->set_attrnames(vright[j]);
                        temp.push_back((*it2)->get_attr(j)->copy());
                        j++;
                    }
                }
                R3->set_natttr(R1->get_natttr() + R2->get_natttr() - c);
                Record *r = new Record;
                for (int i = 0; i < temp.size(); i++)
                {
                    r->addattr(temp[i]->copy());
                }
                // cout <<"(719)";r->print_vector();
                // r->attrptr = temp ;
                // Record * r = temp.copy() ;
                R3->add_to_list(r);
            }
        }
    }
    cout << "***Natural join ended\n";
    return R3;
}