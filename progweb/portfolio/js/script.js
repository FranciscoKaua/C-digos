const meuNome = "Francisco Kauã da Silva Neves"
const funcao = "Estudante de Ciências da Computação"

document.querySelector("#titulo-nome").textContent = meuNome
document.querySelector("#subtitulo").textContent= funcao
document.querySelector("#nome-rodape").textContent = meuNome
document.querySelector("#ano").textContent = new Date().getFullYear()

const habilidades = document.querySelectorAll(".habilidade")
document.querySelector("#contador-habilidades").textContent = `${habilidades.length} habilidades`

const btnTema = document.querySelector("#btn-tema")
btnTema.addEventListener("click", () => {
    document.body.classList.toggle("tema-escuro")
    
    if(document.body.classList.contains("tema-escuro")){
        btnTema.textContent = "Modo claro"
    }else{
        btnTema.textContent = "Modo escuro"
    }
})


const btnFiltros = document.querySelectorAll(".botao-filtro")
const cartaoProjetos = document.querySelectorAll(".cartao-projeto")
btnFiltros.forEach((btn) => {
    btn.addEventListener("click", () => {
        const categoria= btn.dataset.categoria
        
        btnFiltros.forEach((btn) => {
            btn.classList.remove("ativo")
        })
        btn.classList.add("ativo")
        
        cartaoProjetos.forEach((cartao) => {
            if (categoria === "todos" || cartao.dataset.categoria === categoria) {
                cartao.classList.remove("oculto")
            } else {
                cartao.classList.add("oculto")
            }
        })
    })
})


const btnDetalhes = document.querySelectorAll(".botao-detalhes")
btnDetalhes.forEach((btn) => {
    btn.addEventListener("click", () => {
        const cartao = btn.closest("article");
        const detalhes = cartao.querySelector(".detalhes-projeto");
        detalhes.classList.toggle("oculto");
    
        if (detalhes.classList.contains("oculto")) {
            btn.textContent = "Ver detalhes";
        } else {
            btn.textContent = "Ocultar detalhes";
        }
    })
})

