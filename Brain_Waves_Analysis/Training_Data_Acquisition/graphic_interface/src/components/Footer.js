import React from 'react';

import "./footer.css";

import Card from "./Card.js";

class Footer extends React.Component {

	render() {
		return (
			<Card className="footer">
				<h1>Made by:</h1>
				<h2>Vinicius de A. L. e Souza</h2>
				<h2>Yongsun Lim</h2>
			</Card>
		);
	}
}

export default Footer;