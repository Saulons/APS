#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

FILE *pont_dados;

int bubble_sort (int vetor[], int n){
    int aux, tamanho = n, bool=0, movimento=0;

    do{
        bool=0;
        for(int i=0; i < tamanho-1; i++){
            if(vetor[i] > vetor[i+1]){
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                bool = i;
				movimento = movimento + 1;
            }
        }
        tamanho--;
    }while(bool!=0);

    for(int k=0; k < n; k++){
        printf("%d, ", vetor[k]);
    }
	return movimento;
}
int insertion_sort(int vetor[], int n){
    int i, j,aux, movimento = 0;
    for(i=1; i < n; i++){
        aux = vetor[i];
        for(j=i; (j>0) && (aux < vetor[j -1]); j--){
            vetor[j] = vetor[j - 1];
			      movimento = movimento + 1;
        }
        vetor[j] = aux;
    }
    for(int k=0; k < n; k++){
        printf("%d, ", vetor[k]);
    }
	return movimento;
}
int selection_sort (int Vet[], int n){
    int menor, aux, movimento = 0;

    for(int i=0;i<n-1;i++){
        menor=i;
        for(int j=i+1;j<n;j++){
            if(Vet[menor] > Vet[j])
                menor =j;
        }
        if (i!=menor) {
            aux=Vet[i];
            Vet[i]=Vet[menor];
            Vet[menor]=aux;
			      movimento = movimento + 1;
        }
    }
    for(int s=0; s<n; s++){
		    printf("%d, ", Vet[s]);
    }
	  return movimento;
}
//Copiar listas
void copiar(int copia[], int original[],int tamanho){
    for(int f=0 ; f < tamanho ; f++){
        copia[f] = original[f];
    }
}

char separador[] = ";";
int nmrExecProvisorio;

void exportar(char* nomeAlgoritmo, char* tamConj, int tempoExec, int movimentos, char* descConj){
	  printf("%s%s %s%s %d%s %d%s %s%s %d\n", nomeAlgoritmo, separador, tamConj, separador, tempoExec, separador, movimentos, separador, descConj, separador, nmrExecProvisorio);
    fprintf(pont_dados,"%s%s %s%s %d%s %d%s %s%s %d\n", nomeAlgoritmo, separador, tamConj, separador, tempoExec, separador, movimentos, separador, descConj, separador, nmrExecProvisorio);
}

void main()
{
    FILE *pont_arq1, *pont_arq2, *pont_arq3, *pont_arq4, *pont_arq5, *pont_arq6, *pont_arq7, *pont_arq8, *pont_arq9, *pont_arq10, *pont_arq11, *pont_arq12, *pont_arq13, *pont_arq14, *pont_arq15, *pont_arq16, *pont_arq17, *pont_arq18, *pont_arq19, *pont_arq20;
    int numUs, auxUs[20], AuxUs[20], movUs1, movUs2, movUs3, listaUs[20];

	  // PONTEIRO PARA SALVAR OS DADOS OBTIDOS
    pont_dados = fopen("DadosExaminados.txt", "a+");

    printf("\n-------------------------------------- Analise de algoritmos de ordenação ----------------------------------------------\n");
    printf("Digite o número da Execução(PROVISÓRIO): \n");
    scanf("%d", &nmrExecProvisorio); //Digitei 1, o Andrew pode digitar 2 e Saulo 3 por exemplo
    /* Pegando dados do usuario */
  	printf("Analisaremos 20 conjuntos de dados e uma lista definida por voce\n\n");

    printf("Digite quantos numeros haverá na sua lista (até 20 por enquanto): \n");
    scanf("%d", &numUs);

  	for(int a=0; a < numUs; a++){
        printf("Digite %do numero: ", a+1);
        scanf("%d", &listaUs[a]);
    }

    // Copiando Lista Usuario
    copiar(auxUs, listaUs, numUs);
    copiar(AuxUs, listaUs, numUs);

    printf("\n");
    for(int a = 0; a < numUs; a++){
        printf("%d", listaUs[a]);
    }

    // Arrumando a lista do usuario
    printf("\n==================== Lista do usuario Organizada ====================");
    printf("\nBubble Sort ");
    clock_t comeco1us = clock();
    movUs1 = bubble_sort(listaUs, numUs);
    clock_t fim1us = clock();

    printf("\nInsertion Sort ");
    clock_t comeco2us = clock();
    movUs2 = insertion_sort(auxUs, numUs);
    clock_t fim2us = clock();

    printf("\nSelecion Sort ");
    clock_t comeco3us = clock();
    movUs3 = selection_sort(AuxUs, numUs);
    clock_t fim3us = clock();

    //COLOCAR OS DADOS DA LISTA DO USUÁRIO PARA SER SALVO EM UMA FUNÇÃO
    fprintf(pont_dados,"\nAlgoritmo; TamanhoConjunto; TempoExec; nmrMovimentos; DescConjunto; nmrExecucao \n");

    int a = (int) fim1us-comeco1us, b = (int) fim2us-comeco2us, c = (int) fim3us-comeco3us;
    char qtdUs[6];

    sprintf(qtdUs, "%d", numUs);

    printf("\n=============== Exportar Lista do usuario Organizada ================\n");

    exportar("Bubble Sort", qtdUs, a, movUs1, "Criado pelo usuario");
    exportar("Selection Sort", qtdUs, b, movUs2, "Criado pelo usuario");
    exportar("Insertion Sort", qtdUs, c, movUs3, "Criado pelo usuario");

    char sizeConjunto[20][6], desc[20][42];

    // Ponteiro para o arquivo... tem que colocar \\
    // Testando se conseguimos encontrar os arquivos
	  // 1k
    if((pont_arq1 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\1k\\dtaleat1kdup9.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o primeiro arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[0], "1k");
        strcpy(desc[0], "com duplicidade e aleatorio");
    }
	  if((pont_arq2 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\1k\\dtaleat1kuni7.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o segundo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[1], "1k");
        strcpy(desc[1], "com duplicidade e concavo decresceCresce");
    }
	  if((pont_arq3 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\1k\\dtconcv1kdup0.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o terceiro arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[2], "1k");
        strcpy(desc[2], "com duplicidade e Descrescente");
    }
	  if((pont_arq4 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\1k\\dtdecre1kdup5.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o quarto arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[3], "1k");
        strcpy(desc[3], "sem duplicidade e Aleatorio");
    }
	  if((pont_arq5 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\1k\\dtdecre1kuni8.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o quinto arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[4], "1k");
        strcpy(desc[4], "sem duplicidade e Descrescente");
    }
    // 5k
    if((pont_arq6 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtaleat5kdup4.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o sexto arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[5], "5k");
        strcpy(desc[5], "com duplicidade e Aleatorio");
    }
	  if((pont_arq7 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtaleat5kuni1.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o setimo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[6], "5k");
        strcpy(desc[6], "com duplicidade e Concavo-DecresceCensce");
    }
	  if((pont_arq8 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtconcv5kdup4.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o oitavo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[7], "5k");
        strcpy(desc[7], "com duplicidade e Convexo-CresceDescresce");
    }
	  if((pont_arq9 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtconvx5kdup2.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o nono arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[8], "5k");
        strcpy(desc[8], "com duplicidade e Decrescente");
    }
	  if((pont_arq10 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtconvx5kuni6.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[9], "5k");
        strcpy(desc[9], "sem duplicidade e Aleatorio");
    }
	  if((pont_arq11 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtdecre5kdup4.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo primeiro arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[10], "5k");
        strcpy(desc[10], "sem duplicidade e Convexo-CresceDescresce");
    }
	  if((pont_arq12 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\5k\\dtdecre5kuni8.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo segundo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[11], "5k");
        strcpy(desc[11], "sem duplicidade e Descresce");
    }
	  // 10k
	  if((pont_arq13 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\10k\\dtaleat10kdup4.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo terceiro arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[12], "10k");
        strcpy(desc[12], "com duplicidade e Aleatorio");
    }
    if((pont_arq14 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\10k\\dtaleat10kuni7.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo quarto arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[13], "10k");
        strcpy(desc[13], "com duplicidade e Concavo-DecresceCresce");
    }
    if((pont_arq15 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\10k\\dtconcv10kdup6.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo quinto arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[14], "10k");
        strcpy(desc[14], "com duplicidade e Descrescente");
    }
    if((pont_arq16 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\10k\\dtdecre10kdup9.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo sexto arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[15], "10k");
        strcpy(desc[15], "sem duplicidade e Aleatorio");
    }
    if((pont_arq17 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\10k\\dtdecre10kuni9.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo setimo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[16], "10k");
        strcpy(desc[16], "sem duplicidade e Descrescente");
    }
	  // 500
	  if((pont_arq18 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\500\\dtaleat500dup5.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo oitavo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[17], "500");
        strcpy(desc[17], "com duplicidade e Aleatorio");
    }
    if((pont_arq19 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\500\\dtconcv500dup6.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o decimo nono arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[18], "500");
        strcpy(desc[18], "com duplicidade e Concavo-DecresceCresce");
    }
    if((pont_arq20 = fopen("C:\\Users\\pb\\Desktop\\TesteAps\\dados\\500\\dtdecre500uni8.txt", "r")) == NULL){
        printf("\nProblemas ao abrir o vigesimo arquivo \n");
        exit(0);
    }else{
        strcpy(sizeConjunto[19], "500");
        strcpy(desc[19], "sem duplicidade e Descrescente");
    }


    // vetor para o conteudo do arquivo
    int valor1[1000], valor2[1000], valor3[1000], valor4[1000], valor5[1000], valor6[5000], valor7[5000], valor8[5000], valor9[5000], valor10[5000], valor11[5000], valor12[5000], valor13[10000], valor14[10000], valor15[10000], valor16[10000], valor17[10000], valor18[500], valor19[500], valor20[500];
    int i1=0, i2=0, i3=0, i4=0, i5=0, i6=0, i7=0, i8=0, i9=0, i10=0, i11=0, i12=0, i13=0, i14=0, i15=0, i16=0, i17=0, i18=0, i19=0, i20=0;


    // Lendo cada linha do arquivo
    while(!feof(pont_arq1))
    {
        fscanf(pont_arq1,"%i",&valor1[i1]);
        i1++;
    }
    while(!feof(pont_arq2))
    {
        fscanf(pont_arq2,"%i",&valor2[i2]);
        i2++;
    }
    while(!feof(pont_arq3))
    {
        fscanf(pont_arq3,"%i",&valor3[i3]);
        i3++;
    }
    while(!feof(pont_arq4))
    {
        fscanf(pont_arq4,"%i",&valor4[i4]);
        i4++;
    }
    while(!feof(pont_arq5))
    {
        fscanf(pont_arq5,"%i",&valor5[i5]);
        i5++;
    }
    while(!feof(pont_arq6))
    {
        fscanf(pont_arq6,"%i",&valor6[i6]);
        i6++;
    }
    while(!feof(pont_arq7))
    {
        fscanf(pont_arq7,"%i",&valor7[i7]);
        i7++;
    }while(!feof(pont_arq8))
    {
        fscanf(pont_arq8,"%i",&valor8[i8]);
        i8++;
    }
    while(!feof(pont_arq9))
    {
        fscanf(pont_arq9,"%i",&valor9[i9]);
        i9++;
    }
    while(!feof(pont_arq10))
    {
        fscanf(pont_arq10,"%i",&valor10[i10]);
        i10++;
    }
    while(!feof(pont_arq11))
    {
        fscanf(pont_arq11,"%i",&valor11[i11]);
        i11++;
    }
    while(!feof(pont_arq12))
    {
        fscanf(pont_arq12,"%i",&valor12[i12]);
        i12++;
    }
    while(!feof(pont_arq13))
    {
        fscanf(pont_arq13,"%i",&valor13[i13]);
        i13++;
    }
    while(!feof(pont_arq14))
    {
        fscanf(pont_arq14,"%i",&valor14[i14]);
        i14++;
    }
    while(!feof(pont_arq15))
    {
        fscanf(pont_arq15,"%i",&valor15[i15]);
        i15++;
    }
    while(!feof(pont_arq16))
    {
        fscanf(pont_arq16,"%i",&valor16[i16]);
        i16++;
    }
    while(!feof(pont_arq17))
    {
        fscanf(pont_arq17,"%i",&valor17[i17]);
        i17++;
    }
    while(!feof(pont_arq18))
    {
        fscanf(pont_arq18,"%i",&valor18[i18]);
        i18++;
    }
    while(!feof(pont_arq19))
    {
        fscanf(pont_arq19,"%i",&valor19[i19]);
        i19++;
    }
    while(!feof(pont_arq20))
    {
        fscanf(pont_arq20,"%i",&valor20[i20]);
        i20++;
    }

    printf("\n----------------------------------------------- LISTAS DESORDENADAS -------------------------------------------------------\n");

    //>>>> Ler em forma de Matriz ao invez de tantas linhas <<<<
    // Mostrando oq tem no arquivo
    for(int k=0; k < i1; k++) printf("%d, ", valor1[k]);
  	printf("\n");
    for(int k=0; k < i2; k++) printf("%d, ", valor2[k]);
  	printf("\n");
    for(int k=0; k < i3; k++) printf("%d, ", valor3[k]);
  	printf("\n");
    for(int k=0; k < i4; k++) printf("%d, ", valor4[k]);
  	printf("\n");
    for(int k=0; k < i5; k++) printf("%d, ", valor5[k]);
    printf("\n");
    for(int k=0; k < i6; k++) printf("%d, ", valor6[k]);
    printf("\n");
    for(int k=0; k < i7; k++) printf("%d, ", valor7[k]);
    printf("\n");
    for(int k=0; k < i8; k++) printf("%d, ", valor8[k]);
    printf("\n");
    for(int k=0; k < i9; k++) printf("%d, ", valor9[k]);
    printf("\n");
    for(int k=0; k < i10; k++) printf("%d, ", valor10[k]);
    printf("\n");
    for(int k=0; k < i11; k++) printf("%d, ", valor11[k]);
    printf("\n");
    for(int k=0; k < i12; k++) printf("%d, ", valor12[k]);
    printf("\n");
    for(int k=0; k < i13; k++) printf("%d, ", valor13[k]);
    printf("\n");
    for(int k=0; k < i14; k++) printf("%d, ", valor14[k]);
    printf("\n");
    for(int k=0; k < i15; k++) printf("%d, ", valor15[k]);
    printf("\n");
    for(int k=0; k < i16; k++) printf("%d, ", valor16[k]);
    printf("\n");
    for(int k=0; k < i17; k++) printf("%d, ", valor17[k]);
    printf("\n");
    for(int k=0; k < i18; k++) printf("%d, ", valor18[k]);
    printf("\n");
    for(int k=0; k < i19; k++) printf("%d, ", valor19[k]);
    printf("\n");
    for(int k=0; k < i20; k++) printf("%d, ", valor20[k]);


    // CRIANDO LISTAS COPIAS
    int aux1[1000], aux2[1000], aux3[1000], aux4[1000], aux5[1000], aux6[5000], aux7[5000], aux8[5000], aux9[5000], aux10[5000], aux11[5000], aux12[5000], aux13[10000], aux14[10000], aux15[10000], aux16[10000], aux17[10000], aux18[500], aux19[500], aux20[500];
    int Aux1[1000], Aux2[1000], Aux3[1000], Aux4[1000], Aux5[1000], Aux6[5000], Aux7[5000], Aux8[5000], Aux9[5000], Aux10[5000], Aux11[5000], Aux12[5000], Aux13[10000], Aux14[10000], Aux15[10000], Aux16[10000], Aux17[10000], Aux18[500], Aux19[500], Aux20[500];


    // INSERTION
    copiar(aux1, valor1, i1);
    copiar(aux2, valor2, i2);
    copiar(aux3, valor3, i3);
    copiar(aux4, valor4, i4);
    copiar(aux5, valor5, i5);
    copiar(aux6, valor6, i6);
    copiar(aux7, valor7, i7);
    copiar(aux8, valor8, i8);
    copiar(aux9, valor9, i9);
    copiar(aux10, valor10, i10);
    copiar(aux11, valor11, i11);
    copiar(aux12, valor12, i12);
    copiar(aux13, valor13, i13);
    copiar(aux14, valor14, i14);
    copiar(aux15, valor15, i15);
    copiar(aux16, valor16, i16);
    copiar(aux17, valor17, i17);
    copiar(aux18, valor18, i18);
    copiar(aux19, valor19, i19);
    copiar(aux20, valor20, i20);

    // SELECTION
    copiar(Aux1, valor1, i1);
    copiar(Aux2, valor2, i2);
    copiar(Aux3, valor3, i3);
    copiar(Aux4, valor4, i4);
    copiar(Aux5, valor5, i5);
    copiar(Aux6, valor6, i6);
    copiar(Aux7, valor7, i7);
    copiar(Aux8, valor8, i8);
    copiar(Aux9, valor9, i9);
    copiar(Aux10, valor10, i10);
    copiar(Aux11, valor11, i11);
    copiar(Aux12, valor12, i12);
    copiar(Aux13, valor13, i13);
    copiar(Aux14, valor14, i14);
    copiar(Aux15, valor15, i15);
    copiar(Aux16, valor16, i16);
    copiar(Aux17, valor17, i17);
    copiar(Aux18, valor18, i18);
    copiar(Aux19, valor19, i19);
    copiar(Aux20, valor20, i20);


    printf("\n----------------------------------------------- LISTAS ORDENADAS -------------------------------------------------------\n");

    int contMovBubble[20]; //VETOR
    clock_t comeco[20];
    clock_t fim[20];
    clock_t comecoi[20];
    clock_t fimi[20];
    clock_t comecos[20];
    clock_t fims[20];


    // ARRUMANDO A LISTA E PEGANDO O TEMPO
    comeco[0] = clock();
    contMovBubble[0] = bubble_sort(valor1, i1);
    fim[0] = clock();

    comeco[1] = clock();
    contMovBubble[1] = bubble_sort(valor2, i2);
    fim[1] = clock();

    comeco[2] = clock();
    contMovBubble[2] = bubble_sort(valor3, i3);
    fim[2] = clock();

    comeco[3] = clock();
    contMovBubble[3] = bubble_sort(valor4, i4);
    fim[3] = clock();

    comeco[4] = clock();
    contMovBubble[4] = bubble_sort(valor5, i5);
    fim[4] = clock();

    comeco[5] = clock();
    contMovBubble[5] = bubble_sort(valor6, i6);
    fim[5] = clock();

    comeco[6] = clock();
    contMovBubble[6] = bubble_sort(valor7, i7);
    fim[6] = clock();

    comeco[7] = clock();
    contMovBubble[7] = bubble_sort(valor8, i8);
    fim[7] = clock();

    comeco[8] = clock();
    contMovBubble[8] = bubble_sort(valor9, i9);
    fim[8] = clock();

    comeco[9] = clock();
    contMovBubble[9] = bubble_sort(valor10, i10);
    fim[9] = clock();

    comeco[10] = clock();
    contMovBubble[10] = bubble_sort(valor11, i11);
    fim[10] = clock();

    comeco[11] = clock();
    contMovBubble[11] = bubble_sort(valor12, i12);
    fim[11] = clock();

    comeco[12] = clock();
    contMovBubble[12] = bubble_sort(valor13, i13);
    fim[12] = clock();

    comeco[13] = clock();
    contMovBubble[13] = bubble_sort(valor14, i14);
    fim[13] = clock();

    comeco[14] = clock();
    contMovBubble[14] = bubble_sort(valor15, i15);
    fim[14] = clock();

    comeco[15] = clock();
    contMovBubble[15] = bubble_sort(valor16, i16);
    fim[15] = clock();

    comeco[16] = clock();
    contMovBubble[16] = bubble_sort(valor17, i17);
    fim[16] = clock();

    comeco[17] = clock();
    contMovBubble[17] = bubble_sort(valor18, i18);
    fim[17] = clock();

    comeco[18] = clock();
    contMovBubble[18] = bubble_sort(valor19, i19);
    fim[18] = clock();

    comeco[19] = clock();
    contMovBubble[19] = bubble_sort(valor20, i20);
    fim[19] = clock();

    // ORGANIZANDO COM INSERTION SORT
  	int contMovInsert[20];

    comecoi[0] = clock();
    contMovInsert[0] = insertion_sort(aux1, i1);
    fimi[0] = clock();

    comecoi[1] = clock();
    contMovInsert[1] = insertion_sort(aux2, i2);
    fimi[1] = clock();

    comecoi[2] = clock();
    contMovInsert[2] = insertion_sort(aux3, i3);
    fimi[2] = clock();

    comecoi[3] = clock();
    contMovInsert[3] = insertion_sort(aux4, i4);
    fimi[3] = clock();

    comecoi[4] = clock();
    contMovInsert[4] = insertion_sort(aux5, i5);
    fimi[4] = clock();

    comecoi[5] = clock();
    contMovInsert[5] = insertion_sort(aux6, i6);
    fimi[5] = clock();

    comecoi[6] = clock();
    contMovInsert[6] = insertion_sort(aux7, i7);
    fimi[6] = clock();

    comecoi[7] = clock();
    contMovInsert[7] = insertion_sort(aux8, i8);
    fimi[7] = clock();

    comecoi[8] = clock();
    contMovInsert[8] = insertion_sort(aux9, i9);
    fimi[8] = clock();

    comecoi[9] = clock();
    contMovInsert[9] = insertion_sort(aux10, i10);
    fimi[9] = clock();

    comecoi[10] = clock();
    contMovInsert[10] = insertion_sort(aux11, i11);
    fimi[10] = clock();

    comecoi[11] = clock();
    contMovInsert[11] = insertion_sort(aux12, i12);
    fimi[11] = clock();

    comecoi[12] = clock();
    contMovInsert[12] = insertion_sort(aux13, i13);
    fimi[12] = clock();

    comecoi[13] = clock();
    contMovInsert[13] = insertion_sort(aux14, i14);
    fimi[13] = clock();

    comecoi[14] = clock();
    contMovInsert[14] = insertion_sort(aux15, i15);
    fimi[14] = clock();

    comecoi[15] = clock();
    contMovInsert[15] = insertion_sort(aux16, i16);
    fimi[15] = clock();

    comecoi[16] = clock();
    contMovInsert[16] = insertion_sort(aux17, i17);
    fimi[16] = clock();

    comecoi[17] = clock();
    contMovInsert[17] = insertion_sort(aux18, i18);
    fimi[17] = clock();

    comecoi[18] = clock();
    contMovInsert[18] = insertion_sort(aux19, i19);
    fimi[18] = clock();

    comecoi[19] = clock();
    contMovInsert[19] = insertion_sort(aux20, i20);
    fimi[19] = clock();

    // ORGANIZANDO COM SELECTION SORT
  	int contMovSelect[20];

    comecos[0] = clock();
    contMovSelect[0] = selection_sort(Aux1, i1);
    fims[0] = clock();

    comecos[1] = clock();
    contMovSelect[1] = selection_sort(Aux2, i2);
    fims[1] = clock();

    comecos[2] = clock();
    contMovSelect[2] = selection_sort(Aux3, i3);
    fims[2] = clock();

    comecos[3] = clock();
    contMovSelect[3] = selection_sort(Aux4, i4);
    fims[3] = clock();

    comecos[4] = clock();
    contMovSelect[4] = selection_sort(Aux5, i5);
    fims[4] = clock();

    comecos[5] = clock();
    contMovSelect[5] = selection_sort(Aux6, i6);
    fims[5] = clock();

    comecos[6] = clock();
    contMovSelect[6] = selection_sort(Aux7, i7);
    fims[6] = clock();

    comecos[7] = clock();
    contMovSelect[7] = selection_sort(Aux8, i8);
    fims[7] = clock();

    comecos[8] = clock();
    contMovSelect[8] = selection_sort(Aux9, i9);
    fims[8] = clock();

    comecos[9] = clock();
    contMovSelect[9] = selection_sort(Aux10, i10);
    fims[9] = clock();

    comecos[10] = clock();
    contMovSelect[10] = selection_sort(Aux11, i11);
    fims[10] = clock();

    comecos[11] = clock();
    contMovSelect[11] = selection_sort(Aux12, i12);
    fims[11] = clock();

    comecos[12] = clock();
    contMovSelect[12] = selection_sort(Aux13, i13);
    fims[12] = clock();

    comecos[13] = clock();
    contMovSelect[13] = selection_sort(Aux14, i14);
    fims[13] = clock();

    comecos[14] = clock();
    contMovSelect[14] = selection_sort(Aux15, i15);
    fims[14] = clock();

    comecos[15] = clock();
    contMovSelect[15] = selection_sort(Aux16, i16);
    fims[15] = clock();

    comecos[16] = clock();
    contMovSelect[16] = selection_sort(Aux17, i17);
    fims[16] = clock();

    comecos[17] = clock();
    contMovSelect[17] = selection_sort(Aux18, i18);
    fims[17] = clock();

    comecos[18] = clock();
    contMovSelect[18] = selection_sort(Aux19, i19);
    fims[18] = clock();

    comecos[19] = clock();
    contMovSelect[19] = selection_sort(Aux20, i20);
    fims[19] = clock();

    //>>>> CONTINUARIA igual <<<<
  	//COLOCAR OS DADOS DAS LISTAS PARA SEREM SALVOS NA FUNÇÃO
    int tempoDeExec, nmrMovimentos;

    for(int cont = 0; cont < 20; cont++){
        tempoDeExec = (int) fim[cont]-comeco[cont];
        nmrMovimentos = (int) contMovBubble[cont];
        exportar("Bubble Sort", sizeConjunto[cont], tempoDeExec, nmrMovimentos, desc[cont]);
    }

    for(int cont = 0; cont < 20; cont++){
        tempoDeExec = (int) fimi[cont]-comecoi[cont];
        nmrMovimentos = (int) contMovInsert[cont];
        exportar("Insertion Sort", sizeConjunto[cont], tempoDeExec, nmrMovimentos, desc[cont]);
    }
    for(int cont = 0; cont < 20; cont++){
        tempoDeExec = (int) fims[cont]-comecos[cont];
        nmrMovimentos = (int) contMovSelect[cont];
        exportar("Selection Sort", sizeConjunto[cont], tempoDeExec, nmrMovimentos, desc[cont]);
    }
    // Fechando arquivos
	  fclose(pont_dados);
    fclose(pont_arq1);
    fclose(pont_arq2);
    fclose(pont_arq3);
    fclose(pont_arq4);
    fclose(pont_arq5);
    fclose(pont_arq6);
    fclose(pont_arq7);
    fclose(pont_arq8);
    fclose(pont_arq9);
    fclose(pont_arq10);
    fclose(pont_arq11);
    fclose(pont_arq12);
    fclose(pont_arq13);
    fclose(pont_arq14);
    fclose(pont_arq15);
    fclose(pont_arq16);
    fclose(pont_arq17);
    fclose(pont_arq18);
    fclose(pont_arq19);
    fclose(pont_arq20);
}
