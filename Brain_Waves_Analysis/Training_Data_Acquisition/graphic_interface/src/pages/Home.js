import React from 'react';

import "./home.css";

import Card from "../components/Card.js";

class Home extends React.Component {

	render() {
		return (
			<React.Fragment>
				<header className="home-header">
					<h1>Cerebro</h1>
					<h2>Training Data Acquisition</h2>
				</header>
				
				<Card ClassName="home-footer">
					<h1>Made by:</h1>
					<h2>Vinicius de A. L. e Souza</h2>
					<h2>Yongsun Lim</h2>
				</Card>
			</React.Fragment>
		);
	}
}

export default Home;