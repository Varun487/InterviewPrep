class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        # BFS -> Time:O(n^2), Space:O(n^2)
        gene_bank = set(bank)
        if endGene not in gene_bank:
            return -1
        q = []
        q.append([startGene, 0])
        visited = set()
        visited.add(startGene)
        while q:
            gene, num_mutations = q.pop(0)
            if gene == endGene:
                return num_mutations
            for i in range(len(gene)):
                for j in ['A', 'C', 'T', 'G']:
                    mod_gene = gene[:i] + j + gene[i+1:]
                    if mod_gene not in visited and mod_gene in gene_bank:
                        visited.add(mod_gene)
                        q.append([mod_gene, num_mutations + 1])
        return -1
