/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 21:42:12 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/06 17:42:07 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

STRATEGIES PARSSING FDF :

VERSION 1.0

1) open - read le fichier en comptant les \n
	buf apres buf pour connaitre le nombre de lignes
	dans le fichier. - close argv[1] (le fichier)

2) allouer un char ** du nombre de lignes precedement calcule.
	REopen - REread le fichier et stocker le contenu dans le char ** (GNL) - REclose

3) allouer un tableau de tableaux (autant de lignes que char **) de structures (t_list)
	pour chaque lignes du fichier : 
		- compter le nombre de chiffre (de mots)
		- ce qui permet d'alouer le bon nombre de strutctures sur la ligne du t_list **
		- remplir chaque structures de la ligne grace a du strsplit et du atoi
	FREE le char ** utilise lors du GNL

4) A partir de la, on a un tableau de tableaux de type t_list contenant
 les coordonnes X, Y, Z de chaque points. + on connait le nombre de lignes
 et le nombre de colonnes pour chacune des lignes.


VERSION 2.0

1) Open - read le fichier lignes par lignes

2) Chaque lignes est split dans un char ** (selon les espaces)
	- grace a size_tab (nombre de ligne du char **) on connait le nombre de point sur la ligne
	  si 2 lignes n'ont pas le meme nombre de points -> ERROR -> exit.

3) Faire atoi-table sur la ligne lue pour stocker le char ** en int * dans un maillon
	- chaque maillons correspond a une ligne du fichier.
	- close

4)  Allouer un int ** (nombre de lignes = nombre de maillons) et pour chaque lignes du
	int ** mettre le int * d'un maillon.
	- free la liste chainee.

5) A partir de la, nous avons un int ** contenant tous les Z de chaques points
	les positions X et Y sont retoruvees grace aux index du int **
