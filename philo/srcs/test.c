/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <alexandre@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:13:33 by atomasi           #+#    #+#             */
/*   Updated: 2024/12/30 18:01:35 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

#define TIME_TO_COUNT 21000

typedef struct s_counter
{
	pthread_mutex_t count_mutex;
	unsigned int count;
}			t_counter;

void	*thread_routine(void *data)
{
	//chaque thread commence ici
	pthread_t tid;
	t_counter *counter; // pointeur vers la structure dans le main
	unsigned int i;

	tid = pthread_self();
	counter = (t_counter *)data;
	//Pour lire la valeur de count, on verouille le mutex
	pthread_mutex_lock(&counter->count_mutex);
	//On imprime le compte avant que ce thread commence a iterer
	printf("%sThread [%ld]: comppte au depart = %u.%s\n", YELLOW, tid, counter->count, END);
	pthread_mutex_unlock(&counter->count_mutex);
	i = 0;
	while (i < TIME_TO_COUNT)
	{
		//On verouille le mutex le temps d'incrementer
		pthread_mutex_lock(&counter->count_mutex);
		//On incremente TIME_TO_COUNT fois
		//On incremente le compte a chaque iteration
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
		i++;
	}
	//On Imprime le comppte final au moment ou ce thread a termine son porpre compte en verrouillant le mutex
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [%ld]: Compte final = %u%s\n", BLUE, tid, counter->count, END);
	pthread_mutex_unlock(&counter->count_mutex);
	//juste dit une phrase au pif
	printf("%sThread [%ld]: Le plus grand ennui c'est d'exister sans vivre.%s\n", YELLOW, tid, END);
	return (NULL);
}

/*int main()
{
	pthread_t tid1;
	pthread_t tid2;
	//strucuture qui contient le compte des deux threads et les mutex associe.
	t_counter counter;

	//Il y  a qu'un seul thread dans le main donc on peut initilaiser sans mutex
	counter.count = 0;
	// Initialisation du mutex :
	pthread_mutex_init(&counter.count_mutex, NULL);
	printf("le compte attendu est de %s%u%s\n", GREEN, 2 * TIME_TO_COUNT, END);
	//Creation du premier thread
	pthread_create(&tid1, NULL, thread_routine, &counter);
	printf("Main: Creation du premier thread [%ld]\n", tid1);
	//Creation du second thread
	pthread_create(&tid2, NULL, thread_routine, &counter);
	printf("Main : Creation du second thread [%ld]\n", tid2);
	//Le main thread attend que le nouveau thread se termine avec pthread_join
	pthread_join(tid1, NULL);
	printf("Main : union du premier thread [%ld]\n", tid1);
	//pareille avec le second thread
	pthread_join(tid2, NULL);
	printf("Main: union du second thread [%ld]\n", tid2);
	//evaluation du compte final
	// (On peut lire le compte sans s'occuper du mutex car tous nos threads sont unis et qu'on n'est dans la fonction main qui contient un seul thread)
	if (counter.count != (2 * TIME_TO_COUNT))
		printf("%sMain: ERREUR! Le compte est de %u%s", RED, counter.count, END);
	else
		printf("%sMain: OK. Le compte est de %u%s", GREEN, counter.count, END);
	return (0);
}*/

//main de test

int main()
{
	//test des fonction time_manager
	struct timeval start;
	long long			msecs;
	long long			delay;

	delay = 3218;
	gettimeofday(&start, NULL);
	printf("test\n");
	msecs = get_time_in_miliseconds();
	printf("temps en seconde : %ld, temps en microsecondes : %ld\n", start.tv_sec, start.tv_usec);
	printf("temps en milisecondes : %lld\n", msecs);
	printf("temps en milisecondes d'attente : %lld\n", delay);
	ft_usleep(delay);
	msecs = get_time_diff(&start);
	printf("temps entre le debut du programme et maintenant : %lld\n", msecs);
	printf("test de la vrai fonction usleep : \n");
	usleep(3218000);
	msecs = get_time_diff(&start);
	printf("result : %lld\n", msecs);
	return (1);
}
