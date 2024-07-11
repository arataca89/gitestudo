# ```scanf``` e ```getchar()```

Outro caso ```problemático``` é quando o scanf() é usado num laço.
Se você digitar um valor do tipo errado, o scanf() lerá o valor errado
e a execução do laço continuará na sentença após o scanf().
Na próxima iteração do laço o scanf() vai tentar ler novamente,
mas o ```lixo``` deixado da iteração anterior ainda estará lá,
e portanto a chamada corrente do scanf() também não dará certo.
Este comportamento resultará num laço infinito (um laço que nunca termina),
ou terminará e terá um resultado errado.

Há uma maneira simples de resolver este problema;
toda vez que você usar ```getchar()``` (para ler um caracter só) ou ```scanf()```
, você deve ler todo o ```lixo``` restante até o caractere de nova linha.
Colocando as seguinte linhas após chamadas a getchar() ou scanf() o problema é eliminado:
```
        /* Pula o restante da linha */
        while( getchar() != '\n' );
```		
Note que isso não é necessário após todas as chamadas a getchar() ou scanf().
Só depois daquelas chamadas que precedem getchar() (ou scanf()), especialmente em um laço.

A função scanf() na realidade retorna um inteiro que é o número de itens (valores)
lidos com sucesso. Você pode verificar se o scanf() funcionou testando se o valor 
etornado é igual ao número de especificadores de formato no primeiro argumento da função.

```
int main(){

   int total = 0, num;

   while( total < 20 ){
      printf( "Total = %d\n", total );

      printf( "Entre com um numero: " );
      if( scanf("%d", &num) < 1 )
          /* Ignora o resto da linha */
          while( getchar() != '\n' );
		  /* while ((c = getchar()) != '\n' && c != EOF) {} */
      else 
         total += num;
   }

   printf( "Final total = %d\n", total );
}
```
