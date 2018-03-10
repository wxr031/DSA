bool FreeNode(trie_node_t *pNode) {
    for(int i = 0; i < ALPHABET_SIZE; ++i)
        if(pNode->children[i])
            return false;
    return true;
}
bool deleteUtil(trie_node_t *pNode, char key[], int level, int len)
{
    if(level == len)
    {
        int temp = pNode->value;
        pNode->value = 0;
        return temp && FreeNode(pNode);
    }
    int index = key[level] - 'a';
    if(!pNode->children[index])
        return false;
    if(deleteUtil(pNode->children[index], key, level + 1, len))
    {
        delete pNode->children[index];
        pNode->children[index] = nullptr;
        return !pNode->value && FreeNode(pNode);
    }
    return false;
}

void deleteKey(trie_t *pTrie, char key[])
{
    if(!pTrie) return;
    deleteUtil(pTrie->root, key, 0, strlen(key));
}
