#include <iostream>
#include <cctype>

using namespace std;

int verificaCpf (string cpf)
{
    int cpf_array[11];
    int index = 0;
    int verificaDigito1[10];
    int verificaDigito2[10];
    int acumulador1 = 0;
    int acumulador2 = 0;
    int digito1;
    int digito2;

    //transforma a string de cpf em uma string de inteiros.
    for (char c : cpf)
        {

        if (isdigit(c))
            {
                cpf_array[index] = stoi(string(1,c));
                index++;
            }
        }

 for(int i = 0; i < 9; i++)
 {
     verificaDigito1[i] = cpf_array[i]*(10-i);
     acumulador1= acumulador1+verificaDigito1[i];
 }

  for(int i = 1; i < 10; i++)
 {
    verificaDigito2[i] = cpf_array[i]*(11-i);
    acumulador2= acumulador2+verificaDigito2[i];
 }

 if(acumulador1 % 11 == 0|| acumulador1 % 11 == 1)
 {
    digito1 = 0;
 }
 else
 {
     digito1 = 11 - (acumulador1 % 11);
 }

  if(acumulador2 % 11 == 0|| acumulador2 % 11 == 1)
 {
    digito2 = 0;
 }
 else
 {
     digito2 = 11 - (acumulador2 % 11);
 }

 //mensagem de confirmação do cpf
 if(digito1 == cpf_array[9] && digito2 == cpf_array[10])
 {
     cout << "CPF VALIDO" << endl;
 }
 else
 {
     cout << "CPF INVALIDO" << endl;
 }

    return 0;
}

        int main()
        {
            int opcao;
            string cpf_str;
            //cria o menu do sistema
            do
            {
                cout << "Pressione [0] Para terminar." << endl;
                cout << "Pressione [1] Para verificar um CPF." << endl;
                cin >> opcao;

            if(opcao == 1)
            {
                cout << "Digite um numero de CPF." << endl;
                cin >> cpf_str;

                verificaCpf(cpf_str);
            }

            }while(opcao != 0);

           return 0;
        }
