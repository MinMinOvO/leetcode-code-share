

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct tree{
    union{
        int wordidx;
        struct tree *clds[26];
    };
};

struct ll{
    int val;
    struct ll *next;
};

void free_tree(struct tree *t, int layer, int layer_leaf){
    if(layer == layer_leaf){
        free(t);
        return;
    }
    for(int i=0; i<26; ++i){
        if(t->clds[i] != NULL){
            free_tree(t->clds[i], layer+1, layer_leaf);
        }
    }
    free(t);
}

#define LL_APPEND(head, addval, tmp) do {tmp = (struct ll *)malloc(sizeof(struct ll)); tmp->val = (addval); tmp->next=head; head = tmp;} while(0)
#define LL_FREE(head, tmp) do {if(head!=NULL){for(tmp=head->next; tmp!=NULL; head=tmp, tmp=tmp->next){free(head);} free(head);}} while(0)

#define DEBUG 0
#if DEBUG
#define PRINT_0(s) printf(s)
#define PRINT_1(s, arg) printf(s, arg)
#else
#define PRINT_0(s) do {} while(0)
#define PRINT_1(s, arg) do {} while(0)
#endif


int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
    int slen = strlen(s);
    int wordlen = strlen(words[0]);
    if (slen < wordlen){
        *returnSize = 0;
        return NULL;
    }
    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    memset(root->clds, 0, sizeof(root->clds));
    int *exp_words_num = (int *)malloc(sizeof(int) * wordsSize);
    memset(exp_words_num, 0, sizeof(int) * wordsSize);
    int exp_words_cnt = 0;
    for(int i=0; i<wordsSize; ++i){
        char *word = words[i];
        struct tree *t = root;
        for(int j=0; j<wordlen; ++j){
            char c = words[i][j] - 'a';
            if(t->clds[c] == NULL){
                t->clds[c] = (struct tree *)malloc(sizeof(struct tree));
                struct tree *tc = t->clds[c];
                if(j == wordlen-1){
                    tc->wordidx = -1;
                }else{
                    memset(tc->clds, 0, sizeof(t->clds));
                }
            }
            t = t->clds[c];
        }
        if(t->wordidx != -1){
            exp_words_num[t->wordidx] += 1;
        }else{
            t->wordidx = i;
            exp_words_num[i] = 1;
            exp_words_cnt += 1;
        }
    }
    int cnt_mtched_words = 0;
    int *mtched_words_num = (int *)malloc(sizeof(int) * wordsSize);
    memset(mtched_words_num , 0, sizeof(int) * wordsSize);
    struct ll *ans_ll = NULL;
    struct ll *tokens = NULL, *lltmp, *llelt, *lltmp2;
    for(int offset=0; offset < wordlen; ++offset){
        for(int i=offset; i+wordlen<=slen; i+=wordlen){
            struct tree *t = root;
            int endidx = i+wordlen;
            for(int j=i; j<endidx && t != NULL; ++j){
                t = t->clds[s[j]-'a'];
            }
            if(t == NULL){
                if(tokens != NULL){
                    PRINT_0("Popen all tokens\n");
                    cnt_mtched_words = 0;
                    llelt = tokens;
                    while(llelt != NULL){
                        lltmp = llelt->next;
                        mtched_words_num[llelt->val] = 0;
                        free(llelt);
                        llelt=lltmp;
                    }
                    tokens = NULL;
                }
            }else{
                int token = t->wordidx;
                if(mtched_words_num[token] == exp_words_num[token]){
                    lltmp = NULL;
                    llelt = tokens;
                    do{
                        for(; llelt != NULL && llelt->val != token; lltmp = llelt, llelt = llelt->next);
                        if(llelt != NULL){
                            lltmp2 = lltmp;
                            lltmp = llelt;
                            llelt = llelt->next;
                        }
                    }while(llelt != NULL);
                    if(lltmp2 == NULL){
                        llelt = tokens;
                        tokens = NULL;
                    }else{
                        llelt = lltmp2->next;
                        lltmp2->next = NULL;
                    }
                    do{
                        lltmp = llelt->next;
                        mtched_words_num[llelt->val] -= 1;
                        if(mtched_words_num[llelt->val]+1 == exp_words_num[llelt->val]){
                            cnt_mtched_words -= 1;
                        }
                        PRINT_1("    Popen token %d\n", llelt->val);
                        free(llelt);
                        llelt=lltmp;
                    }while(llelt != NULL);
                }
                mtched_words_num[token] += 1;
                LL_APPEND(tokens, token, lltmp);
                PRINT_1("    Append tokens %d\n", tokens->val);
                if(mtched_words_num[token] == exp_words_num[token]){
                    cnt_mtched_words += 1;
                    if(cnt_mtched_words == exp_words_cnt){
                        LL_APPEND(ans_ll, (i+wordlen)-(wordlen*wordsSize), lltmp);
                        PRINT_1("Append ans %d\n", ans_ll->val);
                    }
                }
            }
        }
        PRINT_0("EndIter- Popen all tokens\n");
        if(tokens != NULL){
            cnt_mtched_words = 0;
            llelt = tokens;
            while(llelt != NULL){
                lltmp = llelt->next;
                mtched_words_num[llelt->val] = 0;
                free(llelt);
                llelt=lltmp;
            }
            tokens = NULL;
        }
    }
    int anslen;
    for(llelt = ans_ll, anslen = 0; llelt != NULL; ++anslen, llelt=llelt->next);
    int *ans_arr = (int *)malloc(sizeof(int) * anslen);
    llelt = ans_ll;
    for(int j=anslen-1; j>=0; --j, llelt=llelt->next){
        ans_arr[j] = llelt->val;
    }
    free_tree(root, 0, wordlen);
    free(exp_words_num);
    free(mtched_words_num);
    LL_FREE(ans_ll, lltmp);
    *returnSize = anslen;
    return ans_arr;
}