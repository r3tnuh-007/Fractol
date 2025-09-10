#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <X11/keysym.h>

# define WIDTH 400
# define HEIGHT 250
# define MALLOC_ERR 1

typedef struct s_img
{
    void *img_ptr;
    char *img_pixel_ptr;
    int bits_per_pixel;
    int endian;
    int line_len;

} t_img;

typedef struct s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img img;
}           t_mlx_data;

void my_pixel_put(t_img *img, int x, int y, int color)
{
    int offset;

    offset = (img -> line_len * y) + (x * (img -> bits_per_pixel / 8));
    *((unsigned int *)(offset + img -> img_pixel_ptr)) = color;
    printf("\n O offset é: %d\n O ponteiro eh: %u", offset, img -> img_pixel_ptr);
}

void color(t_mlx_data *data, int color)
{
    for (int y =0; y < HEIGHT; y ++)
    {
        for (int x = 0; x < WIDTH; x ++)
            my_pixel_put(&data -> img, x, y, color);
    }
}

int f(int keysym, t_mlx_data *data)
{
    printf("Entrou");
    if (keysym == XK_Escape)
    {
        printf("The key %d (ESC) has been pressed\n", keysym);
        mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
        mlx_destroy_display(data -> mlx_ptr);
        free(data -> mlx_ptr);
        exit(0);
    }
    else if (keysym == 114) //R
        color(data, 0xff0000);
    else if (keysym == 103) //G
        color(data, 0x00ff00);
    else if (keysym == 98) //B
        color(data, 0x0000ff);
    printf("The key %d has been pressed\n", keysym);
    mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, data -> img.img_ptr, 0, 0);
    return (0);
}

int main(void)
{
    t_mlx_data  data;

    /*Criacao da conexao*/
    data.mlx_ptr = mlx_init();

    if (data.mlx_ptr == NULL)
        return (MALLOC_ERR);
    
    /*Criacao da Janela */
    data.win_ptr = mlx_new_window(data.mlx_ptr,
        WIDTH,
        HEIGHT,
        "First Window"
    );

    if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr);
        free(data.mlx_ptr);
        return (MALLOC_ERR);
    }

    /*Image*/
    data.img.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);

    data.img.img_pixel_ptr = mlx_get_data_addr(data.img.img_ptr,
                                                &data.img.bits_per_pixel,
                                                &data.img.line_len,
                                                &data.img.endian);
    /*Events*/
    mlx_key_hook(data.win_ptr, f, &data);

    /*Loop*/
    mlx_loop(data.mlx_ptr);
    
    mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
    
    return (0);
}