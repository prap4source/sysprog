/*
 * threads_n.c
 * 
 * Copyright 2017 Pradeep Gopanapalli <pgopan@Pradeeps-MacBook-Pro.local>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef enum { Even, Odd, None } Turn;
int count = 0;
Turn turn = None;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

void *even (void *args)
{
  while(1)
  {
    pthread_mutex_lock(&lock);
    while(turn != Even)
      pthread_cond_wait(&condition, &lock);
    printf("even %d\n", count++);
    turn = Odd;
    pthread_cond_broadcast(&condition);
    pthread_mutex_unlock(&lock);
  }
}
void *odd (void *args)
{
  while(1)
  {
    pthread_mutex_lock(&lock);
    while(turn != Odd)
      pthread_cond_wait(&condition, &lock);
    printf("odd %d\n", count++);
    turn = Even;
    pthread_cond_broadcast(&condition);
    pthread_mutex_unlock(&lock);
  }
}

int main ()
{
  char buf[32];

  pthread_t t1,t2;
  pthread_create(&t2, NULL, odd, NULL);
  pthread_create(&t1, NULL, even, NULL);
  sleep(1);
  
  pthread_mutex_lock(&lock);
  printf("Start\n");
  sleep(1);
  turn = Even;
  pthread_cond_broadcast(&condition);
  pthread_mutex_unlock(&lock);
  
  printf("Enter \"end\" to end...\n");
  while(strcmp(gets(buf), "end") != 0);

  return 0;
}
