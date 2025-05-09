# 본 과정 첫 과제

libft 구현

함수 졸라 만들기

# is_alpha

해당 char가 알파벳인지 확인하는 함수

```c
int is_alpha(int c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}
```

# isdigit

해당 char가 숫자인지 확인하는 함수

```c
int isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}
```

# isalnum

해당 char가 알파벳 또는 숫자인지 확인하는 함수

```c
int isalnum(int c)
{
    if (is_alpha(c) || isdigit(c))
        return (1);
    return (0);
}
```

# isascii

해당 char가 ascii인지 확인하는 함수

```c
int isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}
```

# isprint

해당 char가 출력 가능한 문자인지 확인하는 함수 스페이스 포함

```c
int isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}
```

# strlen

문자열의 길이를 반환하는 함수

```c
size_t strlen(const char *s)
{
    size_t i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}
```

# memset

이름: 메모리의 특정 바이트를 설정하는 함수

헤더: string.h

void *memset(void *b, int c, size_t len);

설명: 메모리 시작 주소 b에서 len 바이트 만큼 c로 설정하는 함수

리턴 값: b의 주소

```c
void *memset(void *b, int c, size_t len)
{
    unsigned char *p;

    p = (unsigned char *)b;
    while (len--)
        *p++ = (unsigned char)c;
    return (b);
}
```

```C
void    *ft_memset(void *s, int c, size_t n)
{       
        size_t  i;
        unsigned char   *p;


        p = (unsigned char *)s;
        i = 0;
        while (i < n)
        {
                p[i] = c;
                i++;
        }
        return (s);
}
```
내 코드.

메모리를 바이트 단위로 접근해야하기 때문에

unsigned char 포인터로 형변환을 해주고, c를 unsigned char로 형변환 해줘야한다.

# bzero

메모리의 특정 바이트를 0으로 설정하는 함수

헤더: string.h

void bzero(void *s, size_t n);

설명: 메모리 시작 주소 s에서 n 바이트 만큼 0으로 설정하는 함수

리턴 값 없음

# memcpy

메모리 영역 복사 함수

헤더: string.h

void *memcpy(void *dest, const void *src, size_t n);

설명: src에서 n 바이트 만큼 dest로 복사하는 함수 메모리 영역은 겹치지 않아야 한다. 만약 겹친다면 memcpy 대신 memmove를 사용해야 한다.

리턴 값: dest의 주소

# memmove

메모리 영역 복사 함수

헤더: string.h

void *memmove(void *dest, const void *src, size_t n);

설명: src에서 n 바이트 만큼 dest로 복사하는 함수 메모리 영역이 겹쳐도 안전하다.

그러나 임시 버퍼를 사용하기 때문에 memcpy보다 느리다.

리턴 값: dest의 주소

```c
void *memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    if (d == s || n == 0)
        return (dest);
    if (d < s)
        while (n--)
            *d++ = *s++;
    else
    {
        d += n;
        s += n;
        while (n--)
            *(--d) = *(--s);
    }
    return (dest);
}
```

# strlcpy

문자열 복사 함수

헤더: string.h

size_t strlcpy(char *dest, const char *src, size_t size);

설명: src에서 dest로 size 바이트 만큼 복사하는 함수 size에는 널 문자가 들어갈 공간을 포함해야하기에 전체 size - 1 길이의 문자열을 복사한다. 

리턴 값: src의 길이

```c
size_t strlcpy(char *dest, const char *src, size_t size)
{
    size_t i;

    if (size == 0)
        return (strlen(src));
    i = 0;
    while (i < size - 1 && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (strlen(src));
}
```

# strlcat

문자열 연결 함수

헤더: string.h

설명: src를 dest에 연결하는 함수 size 바이트 만큼 dest에 src를 연결한다. size에는 널 문자가 들어갈 공간을 포함해야하기에 전체 size - 1 길이의 문자열을 복사한다.

리턴 값: dest의 길이 + src의 길이

```c
size_t strlcat(char *dest, const char *src, size_t size)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < size && dest[i] != '\0')
        i++;
    j = 0;
    while (j < size - i - 1 && src[j] != '\0')
    {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (i + strlen(src));
}
```

# toupper

대문자로 변환하는 함수

헤더: ctype.h

int toupper(int c);

설명: 소문자를 대문자로 변환하는 함수

리턴 값: 변환된 대문자, 변환할 수 없는 경우 c를 그대로 반환

```c
int toupper(int c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}
```

# tolower

소문자로 변환하는 함수

헤더: ctype.h

int tolower(int c);

설명: 대문자를 소문자로 변환하는 함수

리턴 값: 변환된 소문자, 변환할 수 없는 경우 c를 그대로 반환

```c

int tolower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}
```

# strchr

문자열에서 특정 문자를 찾는 함수

헤더: string.h

char *strchr(const char *s, int c);

설명: 문자열 s에서 c 문자를 찾는 함수

리턴 값: c 문자가 처음 나오는 위치의 포인터, c 문자가 없는 경우 NULL

```c
char *strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}
```

# strrchr

문자열에서 특정 문자를 찾는 함수

헤더: string.h

char *strrchr(const char *s, int c);

설명: 문자열 s에서 c 문자를 찾는 함수

리턴 값: c 문자가 마지막으로 나오는 위치의 포인터, c 문자가 없는 경우 NULL

strchr과 비슷하지만, strchr은 첫 번째로 나오는 위치이고, 이 함수는 마지막으로 나오는 위치를 찾는 함수

```c
char *strrchr(const char *s, int c)
{
    const char *last = NULL;

    while (*s != '\0')
    {
        if (*s == (char)c)
            last = s;
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return ((char *)last);
}
```

# strncmp

문자열 비교 함수

헤더: string.h

int strncmp(const char *s1, const char *s2, size_t n);

설명: 문자열 s1과 s2를 n 바이트 만큼 비교하는 함수

리턴 값: s1과 s2가 같으면 0, s1이 s2보다 크면 양수, s1이 s2보다 작으면 음수

```c
int strncmp(const char *s1, const char *s2, size_t n)
{
    while (n && *s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return (0);
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
```

# memchr

메모리에서 특정 문자를 찾는 함수

헤더: string.h

void *memchr(const void *s, int c, size_t n);

설명: 메모리 s에서 첫 c 문자를 찾는 함수

리턴 값: c 문자가 처음 나오는 위치의 포인터, c 문자가 없는 경우 NULL

```c
void *memchr(const void *s, int c, size_t n)
{
    const unsigned char *p;

    p = (const unsigned char *)s;
    while (n--)
    {
        if (*p == (unsigned char)c)
            return ((void *)p);
        p++;
    }
    return (NULL);
}
```

# memcmp

메모리 비교 함수

헤더: string.h

int memcmp(const void *s1, const void *s2, size_t n);

설명: 메모리 s1과 s2를 n 바이트 만큼 비교하는 함수

리턴 값: s1과 s2가 같으면 0, s1이 s2보다 크면 양수, s1이 
s2보다 작으면 음수

strcmp와 차이점은 문자열이 아닌 메모리 영역을 비교한다는 점이다.

이는 널 문자가 나오면 멈추는 strcmp와 달리 널 문자 포함 모든 바이트를 비교한다는 점이다.

```c
int memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *p1;
    const unsigned char *p2;

    p1 = (const unsigned char *)s1;
    p2 = (const unsigned char *)s2;
    while (n--)
    {
        if (*p1 != *p2)
            return (*p1 - *p2);
        p1++;
        p2++;
    }
    // p1 - p2를 해도 된다고 생각하겠지만 n이 0일 때는 그냥 0을 리턴해야하기에.
    return (0);
}
```

# strnstr

문자열에서 특정 문자열을 찾는 함수

헤더: string.h

char *strnstr(const char *big, const char *little, size_t len);

설명: 문자열 big에서 little을 len 바이트 만큼 찾는 함수

리턴 값: little이 처음 나오는 위치의 포인터, little이 없는 경우 NULL

```c
char *strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;

    if (*little == '\0')
        return ((char *)big);
    i = 0;
    while (big[i] != '\0' && i < len)
    {
        j = 0;
        while (big[i + j] == little[j] && big[i + j] != '\0' && (i + j) < len)
            j++;
        if (little[j] == '\0')
            return ((char *)&big[i]);
        i++;
    }
    return (NULL);
}
```

# atoi

문자열을 정수로 변환하는 함수

헤더: stdlib.h

int atoi(const char *nptr);

설명: 문자열 nptr을 정수로 변환하는 함수

리턴 값: 변환된 정수, 에러 시 0

```c
int atoi(const char *nptr)
{
    int sign;
    int result;

    sign = 1;
    result = 0;
    while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
        nptr++;
    if (*nptr == '-' || *nptr == '+')
    {
        if (*nptr == '-')
            sign = -1;
        nptr++;
    }
    while (*nptr >= '0' && *nptr <= '9')
    {
        result = result * 10 + (*nptr - '0');
        nptr++;
    }
    return (result * sign);
}
```

# calloc

메모리 할당 함수

헤더: stdlib.h

void *calloc(size_t nmemb, size_t size);

설명: nmemb * size 바이트 만큼 메모리를 할당하고 0으로 초기화하는 함수

리턴 값: 할당된 메모리의 주소, 에러 시 NULL

```c
void *calloc(size_t nmemb, size_t size)
{
    void *ptr;

    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);
    ft_bzero(ptr, nmemb * size);
    return (ptr);
}
```

# strdup

문자열 복사 함수

헤더: string.h

char *strdup(const char *s);

설명: 문자열 s를 복사하는 함수

리턴 값: 복사된 문자열의 주소, 에러 시 NULL

```c
char *strdup(const char *s)
{
    char *ptr;
    size_t len;

    len = strlen(s);
    ptr = (char *)malloc(len + 1);
    if (ptr == NULL)
        return (NULL);
    ft_strlcpy(ptr, s, len + 1);
    return (ptr);
}
```

# substr

char *ft_substr(char const *s, unsigned int start, size_t len);

파라미터 설명
- s: 서브스트링을 추출할 문자열
- start: 서브스트링의 시작 인덱스
- len: 서브스트링의 최대 길이

리턴 값: 서브스트링의 주소, 에러 시 NULL

malloc 사용 가능

설명: malloc으로 메모리를 할당하고, 그 서브스트링은 s의 start 인덱스부터 시작하며, 최대 len 길이만큼 복사한다. 만약 s의 길이가 start보다 작거나, len이 0이면 빈 문자열을 반환한다. 만약 s가 NULL이면 NULL을 반환한다. 만약 malloc이 실패하면 NULL을 반환한다.

```c
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *ptr;
    size_t i;

    if (s == NULL)
        return (NULL);
    if (start >= strlen(s))
        return (ft_strdup(""));
    if (len > strlen(s) - start)
        len = strlen(s) - start;
    ptr = (char *)malloc(len + 1);
    if (ptr == NULL)
        return (NULL);
    i = 0;
    while (i < len && s[start + i] != '\0')
    {
        ptr[i] = s[start + i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}
```

# strjoin

char *ft_strjoin(char const *s1, char const *s2);

문자열 s1과 s2를 합치는 함수

# strtrim

char *ft_strtrim(char const *s1, char const *set);

s1 문자열 앞 뒤에 있는 set 문자열을 잘라낸 새로운 문자열 반환

# split

char **ft_split(char const *s, char c);

문자열 s를 문자 c를 기준으로 나눠서 나뉜 문자열의 배열을 반환

단어 수 카운트 하고

각 단어 malloc 하기

하나가 할당 실패시 지금까지 한 거 다 free

# itoa

char *ft_itoa(int n);

정수를 문자열로 반환

print("%d", n) 같은 느낌

# strmapi

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

문자열 s의 각 문자에 f 함수를 적용시켜서 새로운 문자열을 만드는 함수

# striteri

void ft_striteri(char *s, void (*f)(unsigned int, char*));

위 함수와 비슷하나 새로운 문자열이 아니라 기존 s를 변경

# putchar_fd

void ft_putchar_fd(char c, int fd);

그냥 putchar 함수 output fd를 지정해서 실행하는 함수

주어진 파일 디스크립터로 출력

# putstr_fd

void ft_putstr_fd(char *s, int fd);

putstr을 주어진 파일 디스크립터에 출력

# putendl_fd

void ft_putendl_fd(char *s, int fd);

위 함수에 줄바꿈 문자만 추가

# putnbr_fd

void ft_putnbr_fd(int n, int fd);

정수 n을 문자열처럼 한 글자씩 출력

# 보너스 연결리스트

# lstnew

t_list *ft_lstnew(void *content);

연결리스트 노드 하나 생성 후 반환

# lstadd_front

void ft_lstadd_front(t_list **lst, t_list *new);

리스트 맨 앞에 노드 추가

# lstsize

int ft_lstsize(t_list *lst);

리스트 요소 개수 반환

# lstlast

t_list *ft_lstlast(t_list *lst);

노드의 마지막 요소 반환

# lstadd_back

void ft_lstadd_back(t_list **lst, t_list *new);

맨 끝에 노드 추가하는 함수

# lstdelone

void ft_lstdelone(t_list *lst, void (*del)(void*));

리스트 노드 제거

# lstclear

void ft_lstclear(t_list **lst, void (*del)(void *));

리스트의 모든 노드 삭제

# lstiter

void ft_lstiter(t_list *lst, void (*f)(void *))

리스트에 각 노드에 f 함수 적용하는 함수

# lstmap

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

새로운 연결리스트를 만들어 거기 각 노드에 함수 f를 적용

실패 시 del로 다 삭제