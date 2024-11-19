#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_VIDEOS 100
#define MAX_USERS 100
#define MAX_FAVORITOS 10
 
typedef struct {
    int id;
    char nome[50];
    char categoria[30];
} Video;
 
typedef struct {
    int id;
    char nome[50];
    int favoritos[MAX_FAVORITOS];
    int numFavoritos;
} Usuario;
 
void cadastrarVideo(FILE *arquivo);
void cadastrarUsuario(FILE *arquivoUsuario, FILE *arquivoVideo);
void listarVideos(FILE *arquivo);
void listarUsuarios(FILE *arquivoUsuario, FILE *arquivoVideo);
void atualizarVideo(FILE *arquivo);
void atualizarUsuario(FILE *arquivoUsuario, FILE *arquivoVideo);
void removerRegistro(char *nomeArquivo, int id, size_t tamanhoRegistro);
void mostrarMenu();
 
int main() {
    FILE *arquivoVideo, *arquivoUsuario;
 
    arquivoVideo = fopen("videos.dat", "r+b");
    if (!arquivoVideo) arquivoVideo = fopen("videos.dat", "w+b");
 
    arquivoUsuario = fopen("usuarios.dat", "r+b");
    if (!arquivoUsuario) arquivoUsuario = fopen("usuarios.dat", "w+b");
 
    int opcao;
    do {
        mostrarMenu();
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarVideo(arquivoVideo);
                break;
            case 2:
                cadastrarUsuario(arquivoUsuario, arquivoVideo);
                break;
            case 3:
                listarVideos(arquivoVideo);
                break;
            case 4:
                listarUsuarios(arquivoUsuario, arquivoVideo);
                break;
            case 5:
                atualizarVideo(arquivoVideo);
                break;
            case 6:
                atualizarUsuario(arquivoUsuario, arquivoVideo);
                break;
            case 7: {
                int id;
                printf("ID do vídeo a remover: ");
                scanf("%d", &id);
                removerRegistro("videos.dat", id, sizeof(Video));
                break;
            }
            case 8: {
                int id;
                printf("ID do usuário a remover: ");
                scanf("%d", &id);
                removerRegistro("usuarios.dat", id, sizeof(Usuario));
                break;
            }
        }
    } while (opcao != 9);
 
    fclose(arquivoVideo);
    fclose(arquivoUsuario);
    return 0;
}
 
void mostrarMenu() {
    printf("\n--- Sistema de Streaming ---\n");
    printf("1. Cadastrar Video\n");
    printf("2. Cadastrar Usuario\n");
    printf("3. Listar Videos\n");
    printf("4. Listar Usuarios\n");
    printf("5. Atualizar Video\n");
    printf("6. Atualizar Usuario\n");
    printf("7. Remover Video\n");
    printf("8. Remover Usuario\n");
    printf("9. Sair\n");
    printf("Escolha uma opcao: ");
}
 
void cadastrarVideo(FILE *arquivo) {
    Video video;
    printf("ID do Video: ");
    scanf("%d", &video.id);
    printf("Nome do Video: ");
    scanf(" %[^\n]", video.nome);
    printf("Categoria do Video: ");
    scanf(" %[^\n]", video.categoria);
 
    fseek(arquivo, 0, SEEK_END);
    fwrite(&video, sizeof(Video), 1, arquivo);
    printf("Video cadastrado com sucesso!\n");
}
 
void cadastrarUsuario(FILE *arquivoUsuario, FILE *arquivoVideo) {
    Usuario usuario;
    int id;
    printf("ID do Usuario: ");
    scanf("%d", &usuario.id);
    printf("Nome do Usuario: ");
    scanf(" %[^\n]", usuario.nome);
    usuario.numFavoritos = 0;
 
    printf("Quantos videos favoritar? ");
    scanf("%d", &usuario.numFavoritos);
    for (int i = 0; i < usuario.numFavoritos; i++) {
        printf("ID do video favorito %d: ", i + 1);
        scanf("%d", &id);
        usuario.favoritos[i] = id;
    }
 
    fseek(arquivoUsuario, 0, SEEK_END);
    fwrite(&usuario, sizeof(Usuario), 1, arquivoUsuario);
    printf("Usuario cadastrado com sucesso!\n");
}
 
void listarVideos(FILE *arquivo) {
    Video video;
    rewind(arquivo);
    printf("\n--- Lista de Videos ---\n");
    while (fread(&video, sizeof(Video), 1, arquivo)) {
        printf("ID: %d, Nome: %s, Categoria: %s\n", video.id, video.nome, video.categoria);
    }
}
 
void listarUsuarios(FILE *arquivoUsuario, FILE *arquivoVideo) {
    Usuario usuario;
    Video video;
    rewind(arquivoUsuario);
    printf("\n--- Lista de Usuarios ---\n");
    while (fread(&usuario, sizeof(Usuario), 1, arquivoUsuario)) {
        printf("ID: %d, Nome: %s, Favoritos: ", usuario.id, usuario.nome);
        for (int i = 0; i < usuario.numFavoritos; i++) {
            rewind(arquivoVideo);
            while (fread(&video, sizeof(Video), 1, arquivoVideo)) {
                if (video.id == usuario.favoritos[i]) {
                    printf("%s ", video.nome);
                    break;
                }
            }
        }
        printf("\n");
    }
}
 
void atualizarVideo(FILE *arquivo) {
    Video video;
    int id, encontrado = 0;
    printf("ID do Video a atualizar: ");
    scanf("%d", &id);
 
    rewind(arquivo);
    while (fread(&video, sizeof(Video), 1, arquivo)) {
        if (video.id == id) {
            encontrado = 1;
            printf("Novo nome: ");
            scanf(" %[^\n]", video.nome);
            printf("Nova categoria: ");
            scanf(" %[^\n]", video.categoria);
 
            fseek(arquivo, -sizeof(Video), SEEK_CUR);
            fwrite(&video, sizeof(Video), 1, arquivo);
            printf("Video atualizado com sucesso!\n");
            break;
        }
    }
    if (!encontrado) printf("Video nao encontrado.\n");
}
 
void atualizarUsuario(FILE *arquivoUsuario, FILE *arquivoVideo) {
    Usuario usuario;
    int id, encontrado = 0;
    printf("ID do Usuario a atualizar: ");
    scanf("%d", &id);
 
    rewind(arquivoUsuario);
    while (fread(&usuario, sizeof(Usuario), 1, arquivoUsuario)) {
        if (usuario.id == id) {
            encontrado = 1;
            printf("Novo nome: ");
            scanf(" %[^\n]", usuario.nome);
 
            printf("Quantos videos favoritar? ");
            scanf("%d", &usuario.numFavoritos);
            for (int i = 0; i < usuario.numFavoritos; i++) {
                printf("ID do video favorito %d: ", i + 1);
                scanf("%d", &usuario.favoritos[i]);
            }
 
            fseek(arquivoUsuario, -sizeof(Usuario), SEEK_CUR);
            fwrite(&usuario, sizeof(Usuario), 1, arquivoUsuario);
            printf("Usuario atualizado com sucesso!\n");
            break;
        }
    }
    if (!encontrado) printf("Usuario nao encontrado.\n");
}
 
void removerRegistro(char *nomeArquivo, int id, size_t tamanhoRegistro) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    FILE *temp = fopen("temp.dat", "wb");
    if (!arquivo || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }
 
    void *registro = malloc(tamanhoRegistro);
    while (fread(registro, tamanhoRegistro, 1, arquivo)) {
        int registroID = *(int *)registro;
        if (registroID != id) fwrite(registro, tamanhoRegistro, 1, temp);
    }
 
    fclose(arquivo);
    fclose(temp);
    free(registro);
    remove(nomeArquivo);
    rename("temp.dat", nomeArquivo);
    printf("Registro removido com sucesso.\n");
}
