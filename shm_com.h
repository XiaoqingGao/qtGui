#ifndef SHM_COM_H
#define SHM_COM_H


#define TEXT_SZ 2048

struct _shm_data
{
        int is_written;
        char data[TEXT_SZ];
};

typedef struct _shm_data shm_data ;


#endif // SHM_COM_H
