/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:34:34 by nsakanou          #+#    #+#             */
/*   Updated: 2024/07/02 15:48:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	(void)argv;
	// t_rt	*rt;

	// rt = sf_calloc(sizeof(t_rt), 1);//t_rt構造体のメモリをゼロクリアして割り当てる
	if (argc != 2)
		ERR();
	// else if (open_file(rt, argv[1]))
	// {
	//     rt_init(rt, argv[1]);//ファイルを開いて初期化する
	//     render(rt);//レンダリングを実行する
	//     mlx_loop(rt->mlx);//レンダリング結果を表示するためにMLXのイベントループに入る
	// }

	// rt_free(rt);
	return (0);
}
