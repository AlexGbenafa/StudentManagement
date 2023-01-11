#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Etudiant{
	private:
		int identifiant;
		string nom;
		vector<int>tabNote;
		double moyenne;
		int rang;

	public:
		Etudiant(int unId, string unNom):identifiant(unId), nom(unNom){
			int note;
			do{
				cout << "Entrez une note: "<<endl;
				cin >> note;
				if (note>=0){
					tabNote.push_back(note);
				}
			}while(note>=0);
		};

		int getId(){
			return identifiant;
		}

		string getNom(){
			return nom;
		}

		void getTabNotes(){
			cout<<"NOTES:"<<endl;
			for(int i = 0; i< tabNote.size();i++){
				cout << "NOTE N°" << i+1 << ": "<< tabNote[i]<<endl;
			}
		}

		double getMoyenne(){
			double moy;
			double sum(0);
			for(int i = 0; i<tabNote.size();i++){
				sum += tabNote[i];
			}
			moy = sum/tabNote.size();
			return moy;
		}

		void afficheEtudiant(){
			cout <<"ID: "<< getId() << endl;
			cout <<"Nom: "<< getNom() << endl;
			getTabNotes();
			cout <<"Moyenne: "<< getMoyenne() << endl;
		}
};

class Classe{
	private:
		vector<Etudiant> Etudiants;
		vector<int> rangDeLaClasse;
		int nbrEleveDansLaClasse;
		double moyClasse;
		double moyenneEleve;

	public:
		Classe(Etudiant etudiant){
			int identifiant;
			string nom;

			//Ajouter des étudiants 
			cout << "Combien d'étudiants dans la classe? ";
			cin >> nbrEleveDansLaClasse;
			
			for (int i = 0; i < nbrEleveDansLaClasse; ++i){
				cout << "Identifiant: ";
				cin >> identifiant;

				cout << "Nom:";
				cin >> nom;

				Etudiant etudiantClasse(identifiant, nom);
				Etudiants.push_back(etudiantClasse);
			}
		}

		//Afficher les étudiants de la classe
		void afficheClasse(){
			for (int i = 0; i < Etudiants.size(); i++){
				cout << "ETUDIANT N°" << i+1 << ": " << endl;
				Etudiants[i].afficheEtudiant();
				cout << endl;
				cout << endl;
			}
		}

		//Calculer la moyenne de la classe
		void moyenneClasse(){
			double sum(0);

			for (int i = 0; i < Etudiants.size(); i++){
				moyenneEleve = Etudiants[i].getMoyenne();//On utilise la valeur de retour de la fonction getMoyenne dans la classe Etudiant
				sum += moyenneEleve;
			}

			moyClasse = sum/Etudiants.size();

			cout << "La moyenne de la classe est: " << moyClasse <<endl;
		}

		void listeMoyenne(){
			vector<double> listeMoyennes;

			for (int i = 0; i < Etudiants.size(); i++){
				moyenneEleve = Etudiants[i].getMoyenne();

				listeMoyennes.push_back(moyenneEleve);
			}

			sort(listeMoyennes.begin(), listeMoyennes.end());

			for (int i = 0; i < Etudiants.size(); i++){
				cout << i+1 << "eme: "<< listeMoyennes[i] << endl;
			}

		}
};

int main(){
	Etudiant Etudiant1(0001, "Abdou Ndiaye");
	Etudiant1.afficheEtudiant();

	Classe B2(Etudiant1);
	B2.afficheClasse();
	B2.moyenneClasse();
	B2.listeMoyenne();
	return 0;
}