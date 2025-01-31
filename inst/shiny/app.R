
library("shiny")
library("shinyWidgets")
library("shinythemes")
library("DT")
library("reactlog")
library("shinycssloaders")
library("sentometrics")
library("quanteda")

source("corpus.R")
source("lexicon.R")
source("how.R")
source("valence.R")
source("corpusSummary.R")
source("sentiment.R")
source("sento_lexicon.R")

data("list_lexicons", package = "sentometrics")
data("list_valence_shifters", package = "sentometrics")
options(scipen = 999)
options(shiny.maxRequestSize = 50*1024^2)

# Define UI for application that draws a histogram
ui <- fluidPage(
        theme = shinytheme("cerulean"),
    tags$head(
        tags$link(rel = "stylesheet", type = "text/css", href = "css.css")
    ),
    sidebarPanel(
        style = "margin: 15px",
        load_corpus_ui("load_corpus_csv"),
        lexicon_ui("lexicon_ui"),
        valence_ui("valence_ui"),
        how_ui("how_ui"),
        uiOutput("calculateSentimentButton")
    ),
    mainPanel(
        fluidRow(
            style = "margin: 15px",
            tabsetPanel(
                id = "tabs",
                tabPanel(
                    style = "margin: 15px",
                    title = "Corpus",
                    render_corpus_ui("corpus_table")
                ),
                tabPanel(
                    style = "margin: 15px",
                    title = "Corpus Summary",
                    corpus_summary_ui("corpus_summary_ui")
                ),
                tabPanel(
                    style = "margin: 15px",
                    title = "Sentiment",
                    sentiment_ui("sentiment_ui")
                )
            )
        )
    )
)

myvals <- reactiveValues(
    selectedLexicons = NULL,
    selectedValence = NULL,
    useValence = FALSE,
    lexiconList = list_lexicons,
    valenceList = list_valence_shifters,
    how = NULL,
    valenceMethod = "Bigram"
)

server <- function(input, output, session) {



     corpusFile <- callModule(load_corpus_server, "load_corpus_csv")
     corpus <- callModule(create_corpus_server,"", corpusFile)
     callModule(render_corpus_server,"corpus_table", corpusFile)

     lexModule <- callModule(lexicon_server , "lexicon_ui")
     observe({
         myvals$selectedLexicons <- lexModule$selected
         myvals$lexiconList <- lexModule$lexiconList
     })

     valenceModule <- callModule(valence_server, "valence_ui")
     observe({
         myvals$selectedValence <- valenceModule$selected
         myvals$useValence <- valenceModule$useValence
         myvals$valenceMethod <- valenceModule$method
         myvals$valenceList <- valenceModule$valenceList
     })

     howModule <- callModule(how_server, "how_ui")
     observe({
         myvals$how <- howModule$selected
     })

     corpusSummaryModule <- callModule(corpus_summary_server, "corpus_summary_ui", corpus)

     sentoLexicon <- callModule(build_sento_lexicon, "",myvals)

     output$calculateSentimentButton <- renderUI({
             actionButton(
                 inputId = "calcSentimentButton",
                 label = "Calculate Sentiment",
                 icon = icon("rocket")
             )
     })

     observeEvent(input$calcSentimentButton, {

            if(is.null(sentoLexicon())) {
                showModal(modalDialog(
                    title = "Error",
                    "Select a corpus and lexicon first.."
                ))
            } else {
                updateTabsetPanel(session, "tabs", selected = "Sentiment")
                callModule(sentiment_server, "sentiment_ui", myvals, corpus, sentoLexicon, input$calcSentimentButton )
            }
     })
}

# Run the application
shinyApp(ui = ui, server = server)

