pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Code Check') {
            steps {
                script {
                    def cppcheckCmd = 'cppcheck --project=.cppcheck --xml --xml-version=2 2> cppcheck-result.xml || true'
                    sh cppcheckCmd
                }
            }
            post {
                always {
                    publishCppcheck pattern: 'cppcheck-result.xml'
                }
            }
        }

        stage('Build') {
            steps {
                script {
                    def cmakeCmd = 'cmake -Bbuild -H.'
                    def buildCmd = 'cmake --build build'
                    sh cmakeCmd
                    sh buildCmd
                }
            }
        }

        stage('Run') {
            steps {
                script {
                    def runCmd = './build/square_app'
                    sh runCmd
                }
            }
        }
    }

    post {
        always {
            archiveArtifacts 'build/square_app'
        }
    }
}
