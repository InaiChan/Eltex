#include <stdio.h>
#include <string.h>

struct abonent {
    char name[10];
    char second_name[10];
    char tel[13];
};

void print_menu();
void clean_input_buffer();
void add_abonent(struct abonent abonents[], int *count);
void delete_abonent(struct abonent abonents[], int *count);
void find_abonent(struct abonent abonents[], int count);
void print_all(struct abonent abonents[], int count);

int main(void) {
    struct abonent abonents[100];
    int count_abonent = 0;

    while(1) {
        print_menu();
        
        int input_number;
        if(scanf("%d", &input_number) != 1) {
            printf("Input error");
            clean_input_buffer();
            return 0;
        }

        switch(input_number) {
            case 1:
                add_abonent(abonents, &count_abonent);
                break;

            case 2:
                delete_abonent(abonents, &count_abonent);
                break;

            case 3:
                find_abonent(abonents, count_abonent);
                break;

            case 4:
                print_all(abonents, count_abonent);
                break;

            case 5:
                return 0;
            
            default:
                printf("Попробуйте ещё раз\n\n");
        }
    }
    return 0;
}

void clean_input_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
    return;
}

void print_menu() {
    printf("1) Добавить абонента\n\
2) Удалить абонента\n\
3) Поиск абонентов по имени\n\
4) Вывод всех записей\n\
5) Выход\n");
}

void add_abonent(struct abonent abonents[], int *count) {
    if(*count < 100) {
        printf("Введите имя: ");
        scanf("%9s", abonents[*count].name);
        char c;
        clean_input_buffer();

        printf("Введите фамилию: ");
        scanf("%9s", abonents[*count].second_name);
        clean_input_buffer();

        printf("Введите номер телефона: ");
        scanf("%12s", abonents[*count].tel);
        clean_input_buffer();

        printf("Абонент добавлен\n\n");
        (*count)++;
    } else printf("Справочник переполнен\n\n");
}

void delete_abonent(struct abonent abonents[], int *count) {
    if(*count == 0) {
        printf("Справочник пуст\n");
        return;
    }

    printf("Введите индекс удаляемого абонента(от 1 до %d): ", *count);
    int del_index;
    if(scanf("%d", &del_index) != 1) {
        printf("Input error");
        clean_input_buffer();
        return;
    }

    if(del_index < 1 || del_index > *count) {
        printf("Такого абонента не существует\n");
        return;
    }

    abonents[del_index - 1].name[0] = '\0';
    abonents[del_index - 1].second_name[0] = '\0';
    abonents[del_index - 1].tel[0] = '\0';

    for(int i = del_index - 1; i < *count - 1; i++) {
        abonents[i] = abonents[i + 1];
    }
    *count--;
    printf("Абонент удалён\n\n");
}

void find_abonent(struct abonent abonents[], int count) {
    if(count == 0) {
        printf("Справочник пуст\n\n");
        return;
    }

    printf("Введите имя: ");
    char input_str[10];
    scanf("%9s", input_str);
    int found = 0;

    for(int i = 0; i < count; i++) {
        if(strcmp(abonents[i].name, input_str) == 0) {
            printf("%d: %s %s %s\n", i + 1, abonents[i].name, abonents[i].second_name, abonents[i].tel);
            found = 1;
        }
    }

    if(!found) printf("Абонентов с именем %s не найдено", input_str);
    printf("\n\n");
}

void print_all(struct abonent abonents[], int count) {
    if(count == 0) {
        printf("Справочник пуст\n\n");
        return;
    }
    for(int i = 0; i < count; i++) {
        printf("%d: %s %s %s\n", i + 1, abonents[i].name, abonents[i].second_name, abonents[i].tel);
    }
    printf("\n");
}