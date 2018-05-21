    void TraversalTree(Tree tree) {
        Stack stack = CreateNewStack();
        Tree T = tree;
        while (T || !isEmpty(stack)) {
            while (T) {
                Push(stack, T);
                Push(stack, T);
                T = T->left;
            }
            if (!isEmpty(stack)) {
                T = Pop(stack);
                if (stack->top == NULL || stack->top->value != T) {
                    printf("%c",T->value);
                    T = NULL;
                } else {
                    T = T->right;
                }
            }
        }
    }
