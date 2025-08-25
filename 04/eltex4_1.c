#include <stdio.h>
#include <string.h>

struct abonent {
    char name[10];
    char second_name[10];
    char tel[13];
};

int main(void) {
    struct abonent abonents[100];
    int count_abonent = 0;

    while(1) {
        printf("1) Добавить абонента\n\
2) Удалить абонента\n\
3) Поиск абонентов по имени\n\
4) Вывод всех записей\n\
5) Выход\n");
        
        int input_number;
        if(scanf("%d", &input_number) != 1) {
            printf("Input error");
            return 0;
        }

        switch(input_number) {
            case 1:
                if(count_abonent < 100) {
                    printf("Введите имя: ");
                    scanf("%9s", abonents[count_abonent].name);
                    char c;
                    while((c = getchar()) != '\n' && c != EOF) {}

                    printf("Введите фамилию: ");
                    scanf("%9s", abonents[count_abonent].second_name);
                    while((c = getchar()) != '\n' && c != EOF) {}

                    printf("Введите номер телефона: ");
                    scanf("%12s", abonents[count_abonent].tel);
                    while((c = getchar()) != '\n' && c != EOF) {}

                    printf("Абонент добавлен\n\n");
                    count_abonent++;
                } else printf("Справочник переполнен\n\n");
                break;

            case 2:
                if(count_abonent == 0) {
                    printf("Справочник пуст\n");
                    break;
                }

                printf("Введите индекс удаляемого абонента(от 1 до %d): ", count_abonent);
                int del_index;
                scanf("%d", &del_index);

                if(del_index < 1 || del_index > count_abonent) {
                    printf("Такого абонента не существует\n");
                    break;
                }
                
                abonents[del_index - 1].name[0] = '\0';
                abonents[del_index - 1].second_name[0] = '\0';
                abonents[del_index - 1].tel[0] = '\0';

                for(int i = del_index - 1; i < count_abonent - 1; i++) {
                    abonents[i] = abonents[i + 1];
                }
                count_abonent--;
                printf("Абонент удалён\n\n");
                break;

            case 3:
                if(count_abonent == 0) {
                    printf("Справочник пуст\n\n");
                    break;
                }

                printf("Введите имя: ");
                char input_str[10];
                scanf("%9s", input_str);
                int found = 0;

                for(int i = 0; i < count_abonent; i++) {
                    if(strcmp(abonents[i].name, input_str) == 0) {
                        printf("%d: %s %s %s\n", i + 1, abonents[i].name, abonents[i].second_name, abonents[i].tel);
                        found = 1;
                    }
                }

                if(!found) printf("Абонентов с именем %s не найдено", input_str);
                printf("\n\n");
                break;

            case 4:
                if(count_abonent == 0) {
                    printf("Справочник пуст\n\n");
                    break;
                }
                for(int i = 0; i < count_abonent; i++) {
                    printf("%d: %s %s %s\n", i + 1, abonents[i].name, abonents[i].second_name, abonents[i].tel);
                }

                printf("\n");
                break;

            case 5:
                return 0;
            
            default:
                printf("Попробуйте ещё раз\n\n");
        }
    }


    return 0;
}