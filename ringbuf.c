#include <stdio.h>
#include <stdint.h>

#define BUF_SIZE 8

/* BUF_SIZE must be a power of 2 */

static uint8_t head = 0;
static uint8_t tail = 0;
static uint8_t count = 0;

static uint32_t ring_buf[BUF_SIZE];

static int is_full(void)
{
    return (count == BUF_SIZE);
}

static int is_empty(void)
{
    return (count == 0);
}

static void write_buf(uint32_t data)
{
    if (is_full())
    {
        printf("[WRITE] %02X --> FAIL (buffer full)\n",
               (unsigned int)data);
        return;
    }

    ring_buf[head] = data;
    head = (head + 1) & (BUF_SIZE - 1);
    count++;

    if (is_full())
    {
        printf("[WRITE] %02X --> OK (count=%u) FULL\n",
               (unsigned int)data,
               (unsigned int)count);
    }
    else
    {
        printf("[WRITE] %02X --> OK (count=%u)\n",
               (unsigned int)data,
               (unsigned int)count);
    }
}

static void read_buf(void)
{
    uint32_t data;

    if (is_empty())
    {
        printf("[READ] (empty) --> FAIL (buffer empty)\n");
        return;
    }

    data = ring_buf[tail];
    tail = (tail + 1) & (BUF_SIZE - 1);
    count--;

    printf("[READ] %02X --> OK (count=%u)\n",
           (unsigned int)data,
           (unsigned int)count);
}

int main(void)
{
    uint8_t i;

    printf("=== Ring Buffer Demo ===\n\n");

    /* Fill the buffer */
    for (i = 0; i < BUF_SIZE; i++)
    {
        write_buf(0x41+ i);
    }

    /* Attempt write when full */
    write_buf(0x49);

    /* Read a few elements */
    read_buf();
    read_buf();
    read_buf();

    /* Add more elements */
    write_buf(0x49);
    write_buf(0x4A);
    write_buf(0x4B);

    /* Empty the buffer */
    while (!is_empty())
    {
        read_buf();
    }

    /* Attempt read when empty */
    read_buf();

    return 0;
}
