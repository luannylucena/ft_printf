#include <stdio.h>
#include <stdarg.h>

// Faço uma função 'max' que vai aceitar um certo número de valores int a
// nd vai encontrar o máximo deles em valoores independemente de qtos eu der
// O 1º argumento vai ser o 'int num_args' => número de argumentos e, a partir dele 0 '...' diz que haverá um número variável de argumentos.  

//int max(int num_args, ...)
//{
    // variável de lista. 'args' é o nome da minha variável
    // va_list é o tipo, que basicamente contém as informações necessárias
    // para se trabalhar com uma variável lista de argumentos 
    //va_list args; 

    // A primeira função a ser chmada é a va_start, onde atribui-se a 
    // a variável de lista 'args', além do último argumento que precede a 
    // va_list. NO caso aqui é o 'num_args'.

    //va_start(args, num_args);

    //int i;
    //i = 0;
    //while (i < num_args)
   // {
        // aqui vamos usar o va_args para extrair cada argumento da maneira como funciona. Dou a ela 'args' como o primeiro argumento da sua variável de lista para ir chmando o próximo argumento e, após isso, atribui tb o 'tipo' de argumento que vc deseja extrair, no caso aqui um 'int'.
       // i++;
      //  int x = va_arg(args, int);
     //   printf("x: %d\n", x);
   // }
   // va_end(args); //vai encerrar seu acesso a lista de argumentos
  //  return 0;
         
//}

// Aagora o que quero é que a função me retorne o npumero máximo atual 
int max(int num_args, ...)
{
    va_list args;

    va_start(args, num_args);
    
    // a variavel max vai acompanhar o número maximo atual.
    // 
    int max = 0;
    int i = 0; //vou dizer que se for o primiero argumento na lista, vai ser o numero maximo por padrão (?).
    while (i < num_args)
    {
        i++;
        int x = va_arg(args, int);
        if (i == 0) // aqui estanos olhando para o primeiro número e esse será o numero maixmo por padrão. Então:
            max = x; // se não for == 0, vamos atualizar o 'max', então:
        else if (x > max)
            max = x;
    }
    va_end(args);
    return max;   
}

int main(void)
{
    int max_num = max (4, 10, 20, 14, 16); 
    printf("max_num: %d\n", max_num);

    return 0;
}
