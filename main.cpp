#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
//#include "lib.h"
using namespace std;
struct teo
{
    int num;
    string teorema;
    int capitolo;

};

int contateoremi(teo *vet, int capitolo, int nTeo) 
{
    int num = 0;
    for (int i=0; i<nTeo ; i++) {
        if (vet[i].capitolo == capitolo) {
            num++;
        }
    }
    return num;
}

teo *caricaTeo(const char * nomefile, int nTeo)
{
    teo *vett;
    vett = new teo[nTeo];//creo un vettore di walkers allocato dinamicamente 
    ifstream fin;
    fin.open("teoremi.txt");
    if(fin.fail())
        {
            cout << "Errore apertura file, esco." << endl;
            return NULL;
        }
    for (int i = 0; i < nTeo; i++)
    {
        fin >> vett[i].teorema >> vett[i].capitolo >> vett[i].num;
    }
    fin.close();
    return vett;

}  

vector <double> InputProgresso(vector <double> progresso)
{   
    int tmp;
    ifstream fin;
    fin.open("progresso.txt");
    while(!fin.eof())
    {
        fin >> tmp;
        progresso.push_back(tmp);
    }
    fin.close();
    return progresso;
}

int main()
{
    srand(time(NULL));
   //input in un array di struct
    const int nTeo = 82;
    char input;
    
    vector<double> progresso;
    InputProgresso(progresso);

    teo *vet;
    vet = caricaTeo ("teoremi.txt", nTeo);

    bool pere = true;
    
    cout << "╔════════════════════════════════╗" << endl;
    cout << "║    Benvenuti nel *nome simp*   ║" << endl;
    cout << "║    Premere Y/y per iniziare    ║" << endl;
    cout << "╚════════════════════════════════╝" << endl;

    cin >> input; 

    if(input != 89 and input != 121)
    return 0;
    //richiesta all'utente del capitolo da cui estrarre i teoremi 

    
    cout << "Ecco la lista dei capitoli: \n1. Il campo reale \n2. Elementi e teoria degli spazi metrici \n3. Successioni in spazi euclidei \n4. Serie numeriche \n5. Limiti di funzioni \n6. Continuità \n7. Calcolo differenziale per funzioni di una variabile reale"<< endl;


    
    char scelta;
    char fine;
   
while(pere)
{   
    azio:
    cout << "Digitare il numero del capitolo che si intende studiare." << endl;
    int capito;
    cin >> capito;
    if(capito > 7 or capito < 1)
        {
            cout << "Brodi svegliati"<< endl;
            goto azio;
        }

    int numteo = rand() % nTeo;
    while(vet[numteo].capitolo != capito)
        numteo = rand() % nTeo;

    cout << "\033[31m" << vet[numteo].teorema <<"\033[0m" << endl;

    for(int i = 0; i<progresso.size();i++)
    {
        if(numteo==progresso[i])
            break;
        if(i+1 == progresso.size())
        {
            ofstream fout;
            fout.open("progresso.txt", ios::app);
            fout << numteo << endl;
            progresso.push_back(numteo);
            fout.close();
        } 

    }
    

    cout << "Premi A/a per vedere la soluzione" << endl;
    cin >> scelta; 
    if (scelta == 65 or scelta == 97 )
        system("open SchemiAnalisi1.pdf");
    
    cout << "Le vuoi quelle pere? Y/y per continuare, N/n per affermare di aver studiato tutto" << endl;
    cin>> fine;
    if(fine == 78 or fine == 110)
        pere = false;
    else
        {}
}

    cout << "Hai ripetuto almeno una volta il " << (float) progresso.size()/nTeo * 100 << "%\nCioè " << progresso.size()<< "/"<< nTeo << " teoremi" << endl;
    return 0;
}
