#include <stdio.h>
#include "mlx/mlx.h"

int main() {
    void *mlx_ptr;
    void *win_ptr;

    printf("Iniciando test de MLX\n");
    
    mlx_ptr = mlx_init();
    if (!mlx_ptr) {
        printf("Error: mlx_init() falló\n");
        perror("Error de MLX");
        return 1;
    }
    printf("MLX inicializado correctamente\n");

    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "MLX Test");
    if (!win_ptr) {
        printf("Error: mlx_new_window() falló\n");
        perror("Error de ventana MLX");
        return 1;
    }
    printf("Ventana creada correctamente\n");

    mlx_loop(mlx_ptr);

    return 0;
}