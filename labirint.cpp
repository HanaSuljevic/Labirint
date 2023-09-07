#include "labirint.h"

void Labirint::unesiPodatke(istream &in){
        in >> brojRedova;
        prolazi.resize(brojRedova);
        in >> brojPozicija;
        string linija;
        getline(in, linija);
        for(int i = 0; i < brojRedova/2 - 1; i ++){
            getline(in, linija);
            stringstream linijaStream(linija);
            int tmp;
            while(linijaStream >> tmp) {
                char c;
                linijaStream >> c;
                prolazi[i*2 + 1].push_back(tmp);
                prolazi[i*2 + 2].push_back(tmp);
            }
        }
    }

int Labirint::udaljenost1(int prviZid, int pozicijaPrvog, int drugiZid, int pozicijaDrugog){
    if(prviZid == drugiZid && pozicijaPrvog == pozicijaDrugog) return 0;
    if(prviZid == drugiZid && abs(pozicijaPrvog - pozicijaDrugog) == 1) return 2;
    if((prviZid - 'A') % 2 == 1 && drugiZid-prviZid == 1) return 1;
    return 2 + int(abs(pozicijaPrvog-pozicijaDrugog));
    }

int Labirint::udaljenost(char prviZid, int pozicijaPrvog, char drugiZid, int pozicijaDrugog){

    cout <<"Najkraca udaljenost od " << prviZid <<  pozicijaPrvog << " do " << drugiZid << pozicijaDrugog << " je: ";

    prviZid -= 'A';
    drugiZid -= 'A';
    if(prviZid > drugiZid){
        swap(prviZid, drugiZid);
        swap(pozicijaPrvog, pozicijaDrugog);
    }
    if(prviZid == drugiZid){
        return int(abs(pozicijaDrugog - pozicijaPrvog)) + 1;
    }
    if(drugiZid - prviZid == 1){
        if((prviZid) % 2 == 0) {
            return udaljenost1(prviZid,pozicijaPrvog,drugiZid,pozicijaDrugog);
        }
    }
    vector< vector<int> > udaljenost;
    udaljenost.resize(prolazi.size());
    for(int i = 0; i < udaljenost.size(); i ++){
        udaljenost[i].resize(prolazi[i].size(), INT_MAX);
    }
    int trenutno = prviZid;
    if(prviZid % 2 == 0){
        for(int i = 0; i < prolazi[prviZid + 1].size(); i ++){
            udaljenost[prviZid + 1][i] = udaljenost1(prviZid,pozicijaPrvog,prviZid+1,prolazi[prviZid+1][i]) + 1;

        }
    }else{
        for(int i = 0; i < prolazi[prviZid].size(); i ++){
            udaljenost[prviZid][i] = udaljenost1(prviZid,pozicijaPrvog,prviZid,prolazi[prviZid][i]);
            if(int(abs(prolazi[prviZid][i] - pozicijaPrvog)) == 1) udaljenost[prviZid][i] = 1;
            udaljenost[prviZid+1][i] = udaljenost[prviZid][i] + 1;
        }
        trenutno ++;
    }
    while(trenutno <= drugiZid){
            for(int i = 0; i < prolazi[trenutno].size(); i ++){
            for(int j = 0; j < prolazi[trenutno+1].size(); j ++){
            udaljenost[trenutno+1][j] = min(udaljenost[trenutno+1][j], udaljenost[trenutno][i] + udaljenost1(trenutno, prolazi[trenutno][i],trenutno+1, prolazi[trenutno+1][j]) + 1 );
            }
        }
        for(int j = 0; j < prolazi[trenutno+1].size(); j ++){
        udaljenost[trenutno+2][j] = udaljenost[trenutno+1][j] + 1;
        }
        trenutno+=2;
    }
    int najkraci = INT_MAX;
    if( drugiZid % 2 == 1 ){
        for(int i = 0; i < udaljenost[drugiZid - 1].size(); i ++){
            najkraci = min( najkraci, udaljenost[drugiZid-1][i] + 2 + int(abs(pozicijaDrugog - prolazi[drugiZid-1][i])) );
        }
    }else{
        for(int i = 0; i < udaljenost[drugiZid].size(); i ++){
            najkraci = min( najkraci, udaljenost[drugiZid][i] + 1 + int(abs(pozicijaDrugog - prolazi[drugiZid][i])) );
            if(abs(prolazi[drugiZid][i] - pozicijaDrugog) == 1)
                najkraci = min( najkraci, udaljenost[drugiZid][i]);
        }
    }
    return najkraci;
    }


