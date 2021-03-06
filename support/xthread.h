/* Support functionality for using threads.
   Copyright (C) 2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#ifndef SUPPORT_THREAD_H
#define SUPPORT_THREAD_H

#include <pthread.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

/* Terminate the process (with exit status 0) after SECONDS have
   elapsed, from a helper thread.  The process is terminated with the
   exit function, so atexit handlers are executed.  */
void delayed_exit (int seconds);

/* Terminate the process (with exit status 1) if VALUE is not zero.
   In that case, print a failure message to standard output mentioning
   FUNCTION.  The process is terminated with the exit function, so
   atexit handlers are executed.  */
void xpthread_check_return (const char *function, int value);

/* The following functions call the corresponding libpthread functions
   and terminate the process on error.  */

void xpthread_barrier_init (pthread_barrier_t *barrier,
                            pthread_barrierattr_t *attr, unsigned int count);
void xpthread_barrier_destroy (pthread_barrier_t *barrier);
void xpthread_mutex_lock (pthread_mutex_t *mutex);
void xpthread_mutex_unlock (pthread_mutex_t *mutex);
void xpthread_spin_lock (pthread_spinlock_t *lock);
void xpthread_spin_unlock (pthread_spinlock_t *lock);
void xpthread_cond_wait (pthread_cond_t * cond, pthread_mutex_t * mutex);
pthread_t xpthread_create (pthread_attr_t *attr,
                           void *(*thread_func) (void *), void *closure);
void xpthread_detach (pthread_t thr);
void xpthread_cancel (pthread_t thr);
void *xpthread_join (pthread_t thr);

/* This function returns non-zero if pthread_barrier_wait returned
   PTHREAD_BARRIER_SERIAL_THREAD.  */
int xpthread_barrier_wait (pthread_barrier_t *barrier);

__END_DECLS

#endif /* SUPPORT_THREAD_H */
