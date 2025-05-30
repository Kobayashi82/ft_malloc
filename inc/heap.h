/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzurera- <vzurera-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:12:35 by vzurera-          #+#    #+#             */
/*   Updated: 2025/05/31 21:46:02 by vzurera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#pragma region "Includes"

	#include <stdint.h>

#pragma endregion

#pragma region "Variables"

	#pragma region "Defines"

		#define TOP_CHUNK		0x4					// Bit 2  
		#define IS_MMAPPED		0x2					// Bit 1
		#define PREV_INUSE		0x1					// Bit 0

		#define TINY_MAX		512
		#define TINY_BLOCKS		128
		#define TINY_PAGES		(TINY_BLOCKS  * TINY_MAX) / PAGE_SIZE
		#define TINY_SIZE		PAGE_SIZE * TINY_PAGES
		#define BITMAP_WORDS	4

		#define SMALL_MAX		4096
		#define SMALL_BLOCKS	128
		#define SMALL_PAGES		(SMALL_BLOCKS  * SMALL_MAX) / PAGE_SIZE
		#define SMALL_SIZE		PAGE_SIZE * SMALL_PAGES

	#pragma endregion

	#pragma region "Enumerators"
	
		typedef enum se_heaptype { TINY, SMALL, LARGE } e_heaptype;

	#pragma endregion

	#pragma region "Structures"

		typedef struct s_chunk {
			size_t		prev_size;					// 
			size_t		size;						// Total allocated size of the heap
		} t_chunk;


		typedef struct s_heap t_heap;
		typedef struct s_heap {
			size_t		size;						// Total allocated size of the heap
			size_t		used;						// Memory used in the heap
			size_t		free;						// Memory available for allocation in the heap
			size_t		blocks;						// Number of blocks (TINY_BLOCKS or SMALL_BLOCKS. 0 for LARGE heaps)
			size_t		block_size;					// Size of each block (TINY_MAX or SMALL_MAX. Same as size for LARGE heaps)
			uint64_t	bitmap[BITMAP_WORDS];		// Bitmap for 16-byte blocks (used only in TINY heaps)
			t_heap		*next;						// Pointer to next zone
		} t_heap;

		typedef struct s_range t_range;
		typedef struct s_range {
			void		*start[HEAPS_MAX + 1];		// 
			void		*end[HEAPS_MAX + 1];		// 
		} t_range;

	#pragma endregion

#pragma endregion

#pragma region "Methods"

	size_t	get_pagesize();

	int		range_del(void *ptr, size_t size);
	int		range_add(void *ptr, size_t size);

#pragma endregion
