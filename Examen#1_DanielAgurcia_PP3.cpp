#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

char** Matrix(int);
void PrintMatrix(char**,int);
void FreeMatrix(char**,int);
void FillMatrix(char**,int);
void Jugar(char**);
int Fila(char);
bool Ganar(char**,bool);
void Comer(char**,bool);
void MoverVali(char**,int,int);
int main(){
	char resp='s';
	while(resp == 's' || resp=='S'){
		char** matrix = Matrix(11);
		FillMatrix(matrix,11);
		PrintMatrix(matrix,11);
		Jugar(matrix);
		FreeMatrix(matrix,11);
		cout<<"Desea continuar? [s/n]: ";
		cin>>resp;
	}
return 0;
}

char** Matrix(int size){
	char** matrix = new char*[size];
	for(int i=0; i<size; i++)
		matrix[i]=new char[size];
	return matrix;
}
void PrintMatrix(char** matrix, int size){
	for(int i = 0; i<size;i++){
		for(int j = 0; j<size; j++){
			cout<<"["<<matrix[i][j]<<"]";
		}
		cout<<endl;
	}
}
void FreeMatrix(char** matrix, int size){
	for(int i=0;i<size;i++){
		delete[] matrix[i];
	}
	delete matrix;
}

void Jugar(char** matrix){
	bool ganar=false;
	bool turno=true;
	string coord1;
	string coord2;
	char fila;
	int fila1;
	int fila2;
	int columna1;
	int columna2;
	while(ganar==false){
		if(turno==true){
			cout<<"Ingrese la coordenada de la pieza NEGRA que quiere mover: ";
			cin>>coord1;
			//fila1
			fila=coord1[0];
			fila1=Fila(fila);
			//columna1
			if(coord1.length()==4){
				columna1=10;
			}else{
				columna1=coord1[2]-'0';
			}
			while(matrix[fila1][columna1]!='%'){
				cout<<"La casilla seleccionada no tiene una pieza Negra"<<endl;
				cout<<"Ingrese la coordenada de la pieza NEGRA que quiere mover: ";
                        	cin>>coord1;
                	        //fila1
                       		fila=coord1[0];
                        	fila1=Fila(fila);
                       		//columna1
                       		if(coord1.length()==4){
                               		columna1=10;
                       		}else{
                                	columna1=coord1[2]-'0';
                        	}
			}
			cout<<"Ingrese la coordenada de la casilla donde movera la pieza NEGRA: ";
			cin>>coord2;
			//fila2
			fila=coord2[0];
                        fila2=Fila(fila);
			//columna2
			if(coord2.length()==4){
                                columna2=10;
                        }else{
                                columna2=coord2[2]-'0';
                        }
			/*while(fila1!=fila2 && columna1!=columna2){
                                cout<<"Solo puede moverse vertical u horizontal"<<endl;
                                cout<<"Ingrese la coordenada de la casilla donde movera la pieza BLANCA: ";
                                cin>>coord2;
                                //fila2
                                fila=coord2[0];
                                fila2=Fila(fila);
                                //columna2
                                if(coord2.length()==4){
                                        columna2=10;

                                }else{
                                        columna2=coord2[2]-'0';
                                }

                        }*/
			while((matrix[fila2][columna2]!=' ')||(fila1!=fila2 && columna1!=columna2)){
				cout<<"La casilla seleccionada esta ocupada"<<endl;
				cout<<"Ingrese la coordenada de la casilla donde movera la pieza NEGRA: ";
                 	      	cin>>coord2;
                       	 	//fila2
                       		fila=coord2[0];
                       		fila2=Fila(fila);
                        	//columna2
                       	 	if(coord2.length()==4){
                       	        	columna2=10;
                       	 	}else{
                        		columna2=coord2[2]-'0';
                        	}	
			}
			matrix[fila1][columna1]=' ';
			matrix[fila2][columna2]='%';
			Comer(matrix,turno);
			ganar = Ganar(matrix, turno);
			turno=false;
		}else{
			cout<<"Ingrese la coordenada de la pieza BLANCA que quiere mover: ";
			cin>>coord1;
			//fila1
			fila=coord1[0];
                        fila1=Fila(fila);
			//columna1
			if(coord1.length()==4){
                                columna1=10;
                        }else{
                                columna1=coord1[2]-'0';
                        }
			while(matrix[fila1][columna1]!='&' && matrix[fila1][columna1]!='W'){
                                cout<<"La casilla seleccionada no tiene una pieza blanca"<<endl;
                                cout<<"Ingrese la coordenada de la pieza BLANCA que quiere mover: ";
                                cin>>coord1;
                                //fila1
                                fila=coord1[0];
                                fila1=Fila(fila);
                                //columna1
                                if(coord1.length()==4){
                                        columna1=10;
                                }else{
                                        columna1=coord1[2]-'0';
                                }
                        }
			cout<<"Ingrese la coordenada de la casilla donde movera la pieza BLANCA: ";
                        cin>>coord2;
			//fila2
			fila=coord2[0];
                        fila2=Fila(fila);
			//columna2
			if(coord2.length()==4){
                                columna2=10;

                        }else{
                                columna2=coord2[2]-'0';
                        }
			/*while(fila1!=fila2 && columna1!=columna2){
				cout<<"Solo puede moverse vertical u horizontal"<<endl;
				cout<<"Ingrese la coordenada de la casilla donde movera la pieza BLANCA: ";
                        	cin>>coord2;
                        	//fila2
                        	fila=coord2[0];
                        	fila2=Fila(fila);
                        	//columna2
                        	if(coord2.length()==4){
                                	columna2=10;

                        	}else{
                                	columna2=coord2[2]-'0';
                        	}

			}*/
			while((matrix[fila2][columna2]!=' ')||(fila1!=fila2 && columna1!=columna2)){
                                cout<<"La casilla seleccionada esta ocupada"<<endl;
                                cout<<"Ingrese la coordenada de la casilla donde movera la pieza NEGRA: ";
                                cin>>coord2;
                                //fila2
                                fila=coord2[0];
                                fila2=Fila(fila);
                                //columna2
                                if(coord2.length()==4){
                                        columna2=10;
                               }else{
                                        columna2=coord2[2]-'0';
                                }
                        }
			if(matrix[fila1][columna1]=='W'){
				matrix[fila1][columna1]=' ';
                       		matrix[fila2][columna2]='W';
			}else{
				matrix[fila1][columna1]=' ';
                        	matrix[fila2][columna2]='&';
			}
			Comer(matrix,turno);
			ganar = Ganar(matrix, turno);
			turno=true;
		}
		PrintMatrix(matrix,11);
	}
	if(turno==true){
        	cout<<"FELICIDADES SUECOS HAN GANADO!"<<endl;
        }else{
        	cout<<"FELICIDADES MOSCOVITAS HAN GANADO!"<<endl;
        }
}

void FillMatrix(char** matrix, int size){
	for(int i = 0; i<size;i++)
		for(int j = 0; j<size; j++)
			matrix[i][j]=' ';

	//negras
	matrix[0][4]='%';
	matrix[0][5]='%';
	matrix[0][6]='%';
	matrix[1][4]='%';
        matrix[1][6]='%';
        matrix[2][5]='%';

	matrix[10][4]='%';
        matrix[10][5]='%';
        matrix[10][6]='%';
	matrix[9][4]='%';
        matrix[9][6]='%';
        matrix[8][5]='%';

	matrix[4][0]='%';
        matrix[5][0]='%';
        matrix[6][0]='%';
	matrix[4][1]='%';
        matrix[6][1]='%';
        matrix[5][2]='%';

	matrix[4][10]='%';
        matrix[5][10]='%';
        matrix[6][10]='%';
        matrix[4][9]='%';
        matrix[6][9]='%';
        matrix[5][8]='%';
	//blancas
	matrix[3][5]='&';
        matrix[4][5]='&';
        matrix[5][5]='W';
        matrix[6][5]='&';
        matrix[7][5]='&';

        matrix[5][3]='&';
        matrix[5][4]='&';
        matrix[5][6]='&';
        matrix[5][7]='&';

        matrix[4][4]='&';
        matrix[4][6]='&';
        matrix[6][4]='&';
        matrix[6][6]='&';
	//otros
	matrix[0][0]='X';
	matrix[0][10]='X';
	matrix[10][0]='X';
	matrix[10][10]='X';

}

int Fila(char letra){
	int fila;
	switch(letra){
		case 'A':
			fila=0;
			break;
		case 'B':
			fila=1;
			break;
		case 'C':
			fila=2;
                        break;
		case 'D':
			fila=3;
                        break;
		case 'E':
			fila=4;
                        break;
		case 'F':
			fila=5;
                        break;
		case 'G':
			fila=6;
                        break;
		case 'H':
			fila=7;
                        break;
		case 'I':
			fila=8;
                        break;
		case 'J':
			fila=9;
                        break;
		case 'K':
			fila=10;
			break;
	}
return fila;
}

bool Ganar(char** matrix, bool turno){
	int fila;
	int columna;
	bool gano=false;
	if(turno==true){
		for(int i=0;i<11;i++){
			for(int j=0;j<11;j++){
				if(matrix[i][j]=='W'){
					fila=i;
					columna=j;
				}
			}
		}
		if(matrix[fila-1][columna]=='%' && matrix[fila+1][columna]=='%' && matrix[fila][columna-1]=='%' && matrix[fila][columna+1]=='%'){
		gano=true;
		}
	}else{
		if(matrix[0][0]=='W' || matrix[0][10]=='W' || matrix[10][0]=='W' || matrix[10][10]=='W'){
			gano=true;
		}
}
return gano;
}
void Comer(char** matrix, bool turno){
        for(int i=1;i<10;i++){
                for(int j=1;j<10;j++){
                    if(turno==true){
			    
			    if(matrix[i][j]=='&'){
				    if(matrix[i-1][j]=='%' && matrix[i+1][j]=='%'){
					    matrix[i][j]=' ';
				    }else if(matrix[i][j-1]=='%' && matrix[i][j+1]=='%'){
					    matrix[i][j]=' ';
				    }
			    }
			    
        	    }else{
			    
			    if(matrix[i][j]=='%'){
				    if(matrix[i-1][j]=='&' && matrix[i+1][j]=='&'){
                                            matrix[i][j]=' ';
                                    }else if(matrix[i][j-1]=='&' && matrix[i][j+1]=='&'){
                                            matrix[i][j]=' ';
                                    }
			    }
			    
 	       	    }    
                }
        }
}

