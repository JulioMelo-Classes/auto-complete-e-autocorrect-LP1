#include "LoadBase.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

LoadBase::LoadBase(string dir){
    m_dir = dir;
    fstream palavrasfile;
	palavrasfile.open(m_dir, ios::in);
	int peso;
	string palavra;
	bool swap = true;
    string frase;
    int count = 0;
	while (getline(palavrasfile, frase))
	{
        istringstream iss(frase);
		string token;
		while (getline(iss, token, '\t'))
		{
			if (swap)
			{
				peso = atoi(token.c_str());
				swap = false;
			}
			else
			{
				palavra = token;
				swap = true;
			}
		}
		m_base.push_back(make_pair(peso, palavra));
	}
}

void LoadBase::imprimeBase(bool header){
    size_t t = 5;
    if (!header){
        t = m_base.size();
    }
    for (size_t i = 0; i < t; i++)
    {
        cout <<  m_base[i].first << " | " << m_base[i].second << endl;
    }
    
}
